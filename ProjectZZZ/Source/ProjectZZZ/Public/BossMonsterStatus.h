// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "BossMonsterStatus.generated.h"

// getter 와 setter 를 자동으로 만들어주는 매크로
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class PROJECTZZZ_API UBossMonsterStatus : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	// virtual PriAttributeChange(const )
	//
	// FGameplayAttributeData _health,
	// ATTRIBUTE_ACCESSORS(UBossMonsterStatus, _health);
	//
	// FGameplayAttributeData _maxHealth,
	// ATTRIBUTE_ACCESSORS(UBossMonsterStatus, _maxHealth);
	//
	// FGameplayAttributeData _stemina,
	// ATTRIBUTE_ACCESSORS(UBossMonsterStatus, _stemina);
	//
	// FGameplayAttributeData _maxStemina,
	// ATTRIBUTE_ACCESSORS(UBossMonsterStatus, _maxStemina);
	
};
