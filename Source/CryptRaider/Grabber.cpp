// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	FRotator rotation = GetComponentRotation();
	// UE_LOG(LogTemp, Display, TEXT("Grabber Rotation: %s"), *rotation.ToString());

	AActor * grabbedActor = nullptr;
	bool grab = CanGrab(&grabbedActor);
	
	if (grab) {
		Grab(grabbedActor);
	}
}

bool UGrabber::CanGrab(AActor ** actor) {
	FVector startLocation = GetOwner()->GetActorLocation() + FVector(0,0,64);
	FVector endLocation = startLocation + GetForwardVector() * grabDistance;

	DrawDebugLine(GetWorld(), startLocation, endLocation, FColor::Red);

	FHitResult hitResult;
	FCollisionShape sphere = FCollisionShape::MakeSphere(grabRadius);

	bool isHit = GetWorld()->SweepSingleByChannel(
		hitResult,
		startLocation, endLocation,
		FQuat::Identity,
		ECC_GameTraceChannel2,
		sphere
	);

	if (isHit) {
		*actor = hitResult.GetActor();
		return true;
	}
	
	UE_LOG(LogTemp, Display, TEXT("Not Hit!"));
	return false;
}

void UGrabber::Grab(AActor * actor) {
	UE_LOG(LogTemp, Display, TEXT("Grabbing: %s"), *actor->GetActorNameOrLabel());
}

void UGrabber::Release() {
	UE_LOG(LogTemp, Display, TEXT("Released!"))
}

