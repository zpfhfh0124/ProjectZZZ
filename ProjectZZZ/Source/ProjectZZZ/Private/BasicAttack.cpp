// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicAttack.h"

#include "AbilitySystemComponent.h"
#include "BossCharacter.h"

/*void UBasicAttack::ActiveteAbility(const FGameplayAbilitySpecHandle* Handle, FGameplayAbilityActorInfo* ActorInfo,
                                   const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEvenData)
{
	auto  source = Cast<ABossCharacter>(GetAvatarActorFromActorInfo());
	if (!source)
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
	}
	auto asc = source->GetAbilitySystemComponent();
	auto effectContext = asc->MakeEffectContext();
	effectContext.AddSourceObject(source);
	
	auto damageSpec = MakeOutgoingGameplayEffectSpec(_damageEffect, GetAbilityLevel());
	damageSpec.Data.Get() ->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("Attack.DamageRate")), _damageRate);
	
	asc->ApplyGameplayEffectSpecToTarget(*damageSpec.Data.Get(), asc);
}*/
