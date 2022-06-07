// Fill out your copyright notice in the Description page of Project Settings.


#include "Engager.h"

// Sets default values for this component's properties
UEngager::UEngager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEngager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEngager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// bool UEngager::CheckHitResults(FHitResult& hitResult) {
// 	FVector startLocation = GetComponentLocation();
// 	FVector endLocation = startLocation + GetForwardVector() * range;

// 	FCollisionShape sphere = FCollisionShape::MakeSphere(radius);

// 	bool isHit = GetWorld()->SweepSingleByChannel(
// 		hitResult,
// 		startLocation, endLocation,
// 		FQuat::Identity,
// 		ECC_GameTraceChannel2,
// 		sphere
// 	);

// 	if (isHit) {
// 		return true;
// 	} else {	
// 		return false;
// 	}
	
// }

void UEngager::Engage() {
	TArray<AActor *> overlappingActors;
	GetOwner()->GetOverlappingActors(overlappingActors);

	for (AActor * actor : overlappingActors) {
		if (actor->ActorHasTag("Door")) {
			
		}
	}

}
