// Fill out your copyright notice in the Description page of Project Settings.


#include "BossCharacterStatus.h"
#include "GameplayEffectExtension.h"

void UBossCharacterStatus::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	
	
	
}

void UBossCharacterStatus::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}
