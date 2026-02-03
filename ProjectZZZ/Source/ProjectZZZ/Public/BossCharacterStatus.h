// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "BossCharacterStatus.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
#undef UE_API

/**
 * 
 */
UCLASS()
class PROJECTZZZ_API UBossCharacterStatus : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	
	FGameplayAttributeData _health;
	ATTRIBUTE_ACCESSORS(UBossCharacterStatus, _health);
	FGameplayAttributeData _maxHealth;
	ATTRIBUTE_ACCESSORS(UBossCharacterStatus, _maxHealth);
	FGameplayAttributeData _stamina;
	ATTRIBUTE_ACCESSORS(UBossCharacterStatus, _stamina);
	FGameplayAttributeData _maxStamina;
	ATTRIBUTE_ACCESSORS(UBossCharacterStatus, _maxStamina);
};
