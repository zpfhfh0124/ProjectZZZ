// Fill out your copyright notice in the Description page of Project Settings.



#include "BossCharacter.h"
#include "BossCharacterStatus.h"
#include "BCAbilitySystemComponent.h"

// Sets default values
ABossCharacter::ABossCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	_asc = CreateDefaultSubobject<UBCAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	_status = CreateDefaultSubobject<UBossCharacterStatus>(TEXT("BossStatus"));
}

class UAbilitySystemComponent* ABossCharacter::GetAbilitySystemComponent() const
{
	return _asc;
}

class UBossCharacterStatus* ABossCharacter::GetStatus() const
{
	return _status;
}

// Called when the game starts or when spawned
void ABossCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	InitializeStatus();
}

// Called every frame
void ABossCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABossCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABossCharacter::InitializeStatus()
{
	if (nullptr == _asc)
	{
		return;
	}
	
	if (nullptr == _defaultStatusEffect)
	{
		UE_LOG(LogTemp, Error, TEXT("(%s)캐릭터의 기본 스테이터스 이펙트가 존재하지 않습니다."), *GetName());
		return;
	}
	
	auto context = _asc->MakeEffectContext();
	context.AddSourceObject(this);
	
	auto handle = _asc->MakeOutgoingSpec(_defaultStatusEffect, 0, context);
	if (handle.IsValid())
	{
		_asc->ApplyGameplayEffectSpecToTarget(*handle.Data.Get(), _asc);
	}
	
	GiveDefaultAbilities();
}

void ABossCharacter::GiveDefaultAbilities()
{
	if (nullptr == _asc)
	{
		return;
	}
	
	for (auto& ability : _defaultAbilities)
	{
		// #2 현재 플레이어가 몇가지 기술을 배웠는가
		// #3 [키가 들어가는 자리]
		_asc->GiveAbility(FGameplayAbilitySpec(ability, 0, 0, this));
	}
}

void ABossCharacter::TryActiveAbility(int32 id)
{
	auto spec = _asc->FindAbilitySpecFromInputID(id);
	if (nullptr == spec)
	{
		return;
	}
	
	_asc->TryActivateAbility(spec->Handle);
}
