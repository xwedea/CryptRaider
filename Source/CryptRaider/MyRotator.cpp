// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRotator.h"

// Sets default values for this component's properties
UMyRotator::UMyRotator(FRotator closed, FRotator open, float speed_)
{
	closedRot = closed;
	openRot = open;
	speed = speed_;
}


// Called every frame
FRotator UMyRotator::getNewRotation(bool isOpening, FRotator current, float DeltaTime)
{
	
	FRotator currentRot = current;
	FRotator targetRot = (isOpening) ? openRot : closedRot;
	
	FRotator newRot = FMath::RInterpConstantTo(currentRot, targetRot, DeltaTime, speed);
	return newRot;

}

