// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class CRYPTRAIDER_API UMyRotator
{

public:	
	// Sets default values for this component's properties
	UMyRotator(FRotator closed, FRotator open, float speed_);

	FRotator getNewRotation(bool isOpening, FRotator current, float DeltaTime);

private:
	FRotator closedRot = FRotator(0, 0, 0);
	FRotator openRot = FRotator(0, 90, 0);
	float speed = 4;

	
	
};
