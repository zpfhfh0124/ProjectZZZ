// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BasicAttack.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTZZZ_API UBasicAttack : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSubclassOf<class UGameplayEffect> _damageEffect;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float _damageRate;
};
