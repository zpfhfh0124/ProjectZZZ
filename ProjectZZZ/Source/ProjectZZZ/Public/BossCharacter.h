// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "BossCharacter.generated.h"

UCLASS()
class PROJECTZZZ_API ABossCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABossCharacter();

	class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	UFUNCTION(BlueprintCallable)
	class UBossCharacterStatus* GetStatus() const;
protected:
	UPROPERTY()
	class UBossCharacterStatus* _status;
	UPROPERTY()
	class UAbilitySystemComponent* _asc;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Status")
	TSubclassOf<class UGameplayEffect> _defaultStatusEffect;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void InitializeStatus();
};
