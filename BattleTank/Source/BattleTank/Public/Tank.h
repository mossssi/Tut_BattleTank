// Copyright to Mostafa Khaleghi 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

// Forward declaration

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

	// Called by the engine when actor damage is dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	// Return current health as a percentage of startingHealth from 0 to 1
	UFUNCTION(BlueprintPure, Category = Health)
	float GetHealthPercentage() const;

	FTankDelegate OnDeath;

private:
	ATank();

	int32 StartingHealth = 100;
	int32 CurrentHealth; // Initialise in BeginPlay
};