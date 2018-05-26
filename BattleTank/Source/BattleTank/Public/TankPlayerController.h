// Copyright to Mostafa Khaleghi 2018

#pragma once

#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "TankPlayerController.generated.h" // Always must be the last include

// Forward declaration
class UTankAimingComponent;

/*
* Responsible for helping the player aim.
*/
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	void SetPawn(APawn * InPawn);

	UFUNCTION()
	void OnPossedTankDeath();

	void BeginPlay() override; // override keyword checks the method BeginPlay up to hierarchy and iherit from that.

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
	void FoundAimingComponent(UTankAimingComponent * AimCompRef);

private:
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirecton) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	// Start the tank moving the barrel so that a shot would
	// hit where crosshair intersect the world
	void AimTowardsCrosshair();

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;
};
