// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyDoor.h"

#include "DoorRotator.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UDoorRotator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorRotator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Toggle_isOpening();


private:
	
	
	UPROPERTY(EditAnywhere)
		float speed = 4;
	
	UPROPERTY(EditAnywhere)
		bool isOpening = false;

	UPROPERTY(EditAnywhere)
		FRotator right_openRot = FRotator(0,-90,0);
	UPROPERTY(EditAnywhere)
		FRotator right_closedRot = FRotator(0,0,0);
	UPROPERTY(EditAnywhere)
		FRotator left_openRot = FRotator(0,90,0);
	UPROPERTY(EditAnywhere)
		FRotator left_closedRot = FRotator(0,0,0);


	MyDoor rightDoor;
	MyDoor leftDoor;





	FRotator FindNewRotation(bool isOpening, FRotator current, float DeltaTime);

};

