// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "TankPlayerController.generated.h" // Always must be the last include

// Forward declaration
class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	void BeginPlay() override; // override keyword checks the method BeginPlay up to hierarchy and iherit from that.

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	ATank * GetControlledTank() const;

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirecton) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	// Start the tank moving the barrel so that a shot would
	// hit where crosshair intersect the world
	void AimTowardsCrosshair();

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.33333f;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;
};
