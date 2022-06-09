#pragma once

#include "CoreMinimal.h"




class MyDoor {

public:
	MyDoor();
	MyDoor(FRotator open, FRotator closed);

	void SetComponent(USceneComponent * comp);

	void UpdateRotation(bool isOpening, float DeltaTime, float speed);

	FRotator GetRotation();

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator openRot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator closedRot;
	
	
	USceneComponent * component;

};
