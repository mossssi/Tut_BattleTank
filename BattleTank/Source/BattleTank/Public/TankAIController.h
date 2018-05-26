// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "CoreMinimal.h"
#include "TankAIController.generated.h"

// Forward declaration

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	// How close an AI Tank can get to the Player
	UPROPERTY(EditDefaultsOnly, Category = Setup) // TODO consider EditDefaultsOnly
	float AcceptanceRadius = 8000;

private:
	virtual void BeginPlay() override; // override keyword checks the method BeginPlay up to hierarchy and iherit from that.

	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn * InPawn) override;

	UFUNCTION()
	void OnPossedTankDeath();
};
