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


// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}



ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) return;

	FVector HitLocation; //Out parameter

	if( GetSightRayHitLocation(HitLocation) )
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
	}
}

// get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation( FVector& HitLocation) const{
	
	//find crosshair position
	int32 ViewPortSizex, ViewPortSizey;
	GetViewportSize(ViewPortSizex,ViewPortSizey);
	auto ScreenLocation = FVector2D(ViewPortSizex*CrossHairXLocation, ViewPortSizey*CrossHairYLocation);

	//de project the screen position of the crossahir to a world direction
	// Line trace along that look direction and see if we hit something
	return true;
}

