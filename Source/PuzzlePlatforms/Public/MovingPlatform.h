// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	float Speed;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true), Category = "Platform")
	FVector FinalLocation;

	void AddActiveTrigger();
	void RemoveActiveTrigger();


private:
	FVector Direction;
	FVector Location;

	FVector GlobalStartLocation;
	FVector GlobalTargetLocation;
	FVector TemporarySwapFVector;;
	float DistanceTravelled;
	float TotalDistance;

	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 0;


};
