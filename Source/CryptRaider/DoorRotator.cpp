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

	rightDoor = MyDoor(right_openRot, right_closedRot);
	leftDoor = MyDoor(left_openRot, left_closedRot);

	
	rightDoor.SetComponent
	(
		(USceneComponent *)	
		GetOwner()->GetComponentsByTag(USceneComponent::StaticClass(), "right")[0]
	);

	leftDoor.SetComponent
	(
		(USceneComponent *)	
		GetOwner()->GetComponentsByTag(USceneComponent::StaticClass(), "left")[0]
	);



}


// Called every frame
void UDoorRotator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
	rightDoor.UpdateRotation(
		isOpening,
		DeltaTime,
		speed
	);
	
	leftDoor.UpdateRotation(
		isOpening,
		DeltaTime,
		speed
	);
	
	UE_LOG(LogTemp, Display, TEXT("rightdoor rot: %s"), *rightDoor.GetRotation().ToString());
	UE_LOG(LogTemp, Display, TEXT("leftdoor rot: %s"), *leftDoor.GetRotation().ToString());

}


void UDoorRotator::Toggle_isOpening() {
	isOpening = (isOpening) ? false : true;
}






