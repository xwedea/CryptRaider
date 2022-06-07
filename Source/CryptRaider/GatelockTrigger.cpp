// Fill out your copyright notice in the Description page of Project Settings.


#include "GatelockTrigger.h"

// Sets default values for this component's properties
UGatelockTrigger::UGatelockTrigger()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UGatelockTrigger::BeginPlay() {
	Super::BeginPlay();
	
}

void UGatelockTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UGatelockTrigger::SetMover(UMover * Mover) {
	mover = Mover;
}


void UGatelockTrigger::DisplayOptions() {
	
}

void UGatelockTrigger::ToggleGate() {

	TArray<UActorComponent *> doors =  GetOwner()->GetComponentsByTag(UActorComponent::StaticClass(), "door");
	
	// check if locked

	if (isOpen) {
		for (UActorComponent * e : doors) {
			UPrimitiveComponent * door = (UPrimitiveComponent *) e;
			if (door->ComponentHasTag("left")) {
				door->SetWorldRotation(left_closed);
			} else if (door->ComponentHasTag("right")) {
				door->SetWorldRotation(right_closed);
			}
		}
		isOpen = false;
	} else {
		for (UActorComponent * e : doors) {
			UPrimitiveComponent * door = (UPrimitiveComponent *) e;
			if (door->ComponentHasTag("left")) {
				door->SetWorldRotation(left_open);
			} else if (door->ComponentHasTag("right")) {
				door->SetWorldRotation(right_open);
			}
		}
		isOpen = true;
	}
	
}







