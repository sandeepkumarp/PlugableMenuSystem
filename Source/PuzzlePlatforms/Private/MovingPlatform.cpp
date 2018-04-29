// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	Speed = 80;
	SetMobility(EComponentMobility::Movable);

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActiveTriggers > 0)
	{
		if (HasAuthority())
		{
			TotalDistance = (GlobalTargetLocation - GlobalStartLocation).Size();
			DistanceTravelled = (Location - GlobalStartLocation).Size();

			if (DistanceTravelled >= TotalDistance)
			{
				TemporarySwapFVector = GlobalStartLocation;
				GlobalStartLocation = GlobalTargetLocation;
				GlobalTargetLocation = TemporarySwapFVector;
			}

			Direction = (GlobalTargetLocation - GetActorLocation()).GetSafeNormal();
			Location += Speed * DeltaTime * Direction;
			SetActorLocation(Location);
		}
	}
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	Location = GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(FinalLocation);
	TotalDistance = (GlobalTargetLocation - GlobalStartLocation).Size();
	DistanceTravelled = (Location - GlobalStartLocation).Size();

}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	ActiveTriggers--;
	if (ActiveTriggers < 0)
	{
		ActiveTriggers = 0;
	}
}
