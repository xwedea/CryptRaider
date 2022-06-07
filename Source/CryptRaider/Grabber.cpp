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

	UPhysicsHandleComponent * handler = GetPhysicsHandleComponent();
	// Grabbing
	FHitResult hitResult; // passsed as out parameter
	if (CanGrab(hitResult) && !handler->GetGrabbedComponent()) {
		DrawDebugSphere(
			GetWorld(), 
			hitResult.ImpactPoint,
			10,
			10,
			FColor::Blue
		);
	}

	FVector targetLocation = GetComponentLocation() + GetForwardVector() * holdDistance;
	handler->SetTargetLocationAndRotation(targetLocation, GetComponentRotation());
}


void UGrabber::Grab() {
	FHitResult hitResult;
	if (!CanGrab(hitResult)) {
		return;
	}

	UE_LOG(LogTemp, Display, TEXT("Grabbing: %s"), *hitResult.GetActor()->GetActorNameOrLabel());
	UPhysicsHandleComponent * handler = GetPhysicsHandleComponent();
	UPrimitiveComponent * hitComponent = hitResult.GetComponent();
	hitComponent->WakeAllRigidBodies();
	handler->GrabComponentAtLocationWithRotation(
		hitComponent,
		NAME_None,
		hitResult.ImpactPoint,
		GetComponentRotation()
	);
	// add grabbed tag
	hitResult.GetActor()->Tags.Add(TEXT("Grabbed"));
}


bool UGrabber::CanGrab(FHitResult& hitResult) {
	FVector startLocation = GetComponentLocation();
	FVector endLocation = startLocation + GetForwardVector() * grabDistance;

	FCollisionShape sphere = FCollisionShape::MakeSphere(grabRadius);

	bool isHit = GetWorld()->SweepSingleByChannel(
		hitResult,
		startLocation, endLocation,
		FQuat::Identity,
		ECC_GameTraceChannel2,
		sphere
	);

	if (isHit) {
		return true;
	} else {	
		return false;
	}
	
}

void UGrabber::Release() {
	UPhysicsHandleComponent * handler = GetPhysicsHandleComponent();
	UPrimitiveComponent * grabbedComp = handler->GetGrabbedComponent();
	if (grabbedComp) {
		UE_LOG(LogTemp, Display, TEXT("Releasing: %s"), *grabbedComp->GetName());
		handler->ReleaseComponent();

		AActor * grabbedActor = grabbedComp->GetOwner();
		grabbedActor->Tags.Remove(TEXT("Grabbed"));
	}
}


UPhysicsHandleComponent * UGrabber::GetPhysicsHandleComponent() const {
	UPhysicsHandleComponent * handler = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (handler == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("%s missing UPhysicsHandleComponent!"), *GetOwner()->GetName());
	}

	return handler;
}