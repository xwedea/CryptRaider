// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorRotator.h"

// Sets default values for this component's properties
UDoorRotator::UDoorRotator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorRotator::BeginPlay()
{
	Super::BeginPlay();

	// ...

	rightDoor = (USceneComponent *) \
		GetOwner()->GetComponentsByTag(USceneComponent::StaticClass(), "right")[0];
	leftDoor = (USceneComponent *) \
		GetOwner()->GetComponentsByTag(USceneComponent::StaticClass(), "left")[0];
	



}


// Called every frame
void UDoorRotator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	
	// right
	FRotator right_currentRot = rightDoor->GetComponentRotation();
	FRotator right_targetRot = (isOpening) ? right_openRot : right_closedRot;
	FRotator right_newRot = FMath::RInterpConstantTo(right_currentRot, right_targetRot, DeltaTime, speed);
	rightDoor->SetWorldRotation(right_newRot);


}

// FRotator UDoorRotator::FindNewRotation(bool isOpening, FRotator current, float DeltaTime) {
	// FRotator currentRot = current;
	// FRotator targetRot = (isOpening) ? openRot : closedRot;
	
	// FRotator newRot = FMath::RInterpConstantTo(currentRot, targetRot, DeltaTime, speed);
	// return newRot;

// }





