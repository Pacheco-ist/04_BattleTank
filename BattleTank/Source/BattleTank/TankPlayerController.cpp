// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto PossessededTank = GetControlledTank();
	if( PossessededTank ){
		UE_LOG(LogTemp, Warning, TEXT("Controlling %s"), *(PossessededTank->GetName()));
	}else{
		UE_LOG(LogTemp, Error, TEXT("Missing tank"));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}



