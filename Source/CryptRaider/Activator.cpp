// Fill out your copyright notice in the Description page of Project Settings.


#include "Activator.h"
#include "GatelockTrigger.h"

// Sets default values for this component's properties
UActivator::UActivator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActivator::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActivator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	

}

void UActivator::Use() {
	FHitResult hitResult;
	if (!CheckHitResults(hitResult)) {
		UE_LOG(LogTemp, Display, TEXT("No Hit For Activator!"));
		return;
	}
	
	UPrimitiveComponent * hitComponent = hitResult.GetComponent();
	if (hitComponent->ComponentHasTag("gatelock")) {
		ActivateGatelock(hitComponent);
	}
	
}

void UActivator::ActivateGatelock(UPrimitiveComponent * hitComponent) {
	UE_LOG(LogTemp, Display, TEXT("Activating Gatelock..."));
	UGatelockTrigger * gatelock = (UGatelockTrigger *) hitComponent;
	gatelock->ToggleGate();

}




bool UActivator::CheckHitResults(FHitResult& hitResult) {
	FVector startLocation = GetComponentLocation();
	FVector endLocation = startLocation + GetForwardVector() * range;
	FCollisionShape sphere = FCollisionShape::MakeSphere(radius);

	bool isHit = GetWorld()->SweepSingleByChannel(
		hitResult,
		startLocation, endLocation,
		FQuat::Identity,
		ECC_GameTraceChannel3,
		sphere
	);

	if (isHit) {
		return true;
	} else {	
		return false;
	}
}

