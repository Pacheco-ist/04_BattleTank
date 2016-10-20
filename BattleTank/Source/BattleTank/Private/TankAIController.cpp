// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PossessededTank = GetPlayerTank();
	if (PossessededTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI found player: %s"), *(PossessededTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Missing tank on AI Controller"));
	}
}


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if( GetPlayerTank()){
		//TODO move towards player

		//TODO AIm towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());


		//TODO Fire if ready
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerTank) return nullptr;
	return Cast<ATank>(PlayerTank);
}




