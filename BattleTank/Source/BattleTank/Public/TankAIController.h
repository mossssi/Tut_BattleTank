// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "CoreMinimal.h"
#include "TankAIController.generated.h"

// Forward declaration
class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	

public:
	ATank * GetControlledTank() const;

	virtual void BeginPlay() override; // override keyword checks the method BeginPlay up to hierarchy and iherit from that.

	virtual void Tick(float DeltaTime) override;

private:
	ATank * PlayerTank = nullptr;

	ATank * GetPlayerTank() const;

	FVector HitLocation = FVector(0);
};
