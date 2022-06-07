// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerArea.h"

// Sets default values for this component's properties
UTriggerArea::UTriggerArea()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// SetBoxExtent(FVector(50,50,50));
}

// Called when the game starts
void UTriggerArea::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
	
}

// Called every frame
void UTriggerArea::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (CheckIfUnlocked()) {
		UE_LOG(LogTemp, Display, TEXT("Unlocked!"));
		mover->SetShouldMove(true);
	}
	
}

bool UTriggerArea::CheckIfUnlocked() {
	TArray<AActor *> overlapActors; 
	GetOverlappingActors(overlapActors);
	for  (int i = 0; i < overlapActors.Num(); i++) {
		AActor * actor = overlapActors[i];
		if (actor->ActorHasTag(keyTag)) {
			UPrimitiveComponent * primitiveActor = Cast<UPrimitiveComponent>(actor->GetRootComponent());
			if (primitiveActor != nullptr) {
				primitiveActor->SetSimulatePhysics(false);
			}
			actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
			return true;
		}
	}
	return false;
}



void UTriggerArea::TriggerParent() {
	// 
}

void UTriggerArea::SetMover(UMover * newMover) {
	mover = newMover;
}



