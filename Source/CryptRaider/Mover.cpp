// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	// ...

	originalLocation = GetOwner()->GetActorLocation();
	endLocation = originalLocation + moveOffset;
	speed = FVector::Distance(originalLocation, endLocation) / moveTime;

	
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Move(DeltaTime);

	// ...
}

void UMover::Move(float DeltaTime) {

	if (shouldMove) {
		FVector currentLocation = GetOwner()->GetActorLocation();
		FVector newLocation = FMath::VInterpConstantTo(currentLocation, endLocation, DeltaTime, speed);
	
		GetOwner()->SetActorLocation(newLocation);
	}

	
}

