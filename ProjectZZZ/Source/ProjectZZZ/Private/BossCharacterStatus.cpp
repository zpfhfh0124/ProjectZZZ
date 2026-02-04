// Fill out your copyright notice in the Description page of Project Settings.


#include "BossCharacterStatus.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffect.h"

void UBossCharacterStatus::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	
	if (Attribute == Get_maxHealthAttribute())
	{
		AdjustChangeMaxStatus(_health, _maxHealth, NewValue, Get_healthAttribute());
	}
	else if (Attribute == Get_maxStaminaAttribute())
	{
		AdjustChangeMaxStatus(_stamina, _maxStamina, NewValue, Get_staminaAttribute());
	}
	
}

void UBossCharacterStatus::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
	if (Data.EvaluatedData.Attribute == Get_healthAttribute())
	{
		Set_health(FMath::Clamp(Get_health(), 0.f, Get_maxHealth()));
	}
	else if (Data.EvaluatedData.Attribute == Get_staminaAttribute())
	{
		Set_stamina(FMath::Clamp(Get_stamina(), 0.f, Get_maxStamina())); // 0 보다는 크고 max 보다는 작게 설정한다. 
	}
}

void UBossCharacterStatus::AdjustChangeMaxStatus(FGameplayAttributeData& affectAttribute,
	const FGameplayAttributeData& maxAttribute, float newValue, const FGameplayAttribute& affectAttributeProperty)
{
	auto asc = GetOwningAbilitySystemComponent();
	const float currentMax = maxAttribute.GetCurrentValue();
	if (false == FMath::IsNearlyEqual(currentMax, newValue) && asc)
	{
		const float current = affectAttribute.GetCurrentValue();
		float delta = (0 <= currentMax) ? (newValue - currentMax) : newValue;
		asc->ApplyModToAttributeUnsafe(affectAttributeProperty, EGameplayModOp::Additive, delta);
	}
}
