// Fill out your copyright notice in the Description page of Project Settings.


#include "ScriptCharacter01.h"

// Sets default values
AScriptCharacter01::AScriptCharacter01()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScriptCharacter01::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScriptCharacter01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AScriptCharacter01::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

