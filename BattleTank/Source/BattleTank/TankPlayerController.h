// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;

	void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

	// Move barrel to aim at the crosshair
	void AimTowardsCrosshair();

private:

	//Return out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
