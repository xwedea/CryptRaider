
#include "MyDoor.h"

MyDoor::MyDoor(FRotator open, FRotator closed) {
	component = nullptr;
	closedRot = closed;
	openRot = open;
}

MyDoor::MyDoor() {
	component = nullptr;
	closedRot = FRotator(0,0,0);
	openRot = FRotator(0,-90,0);
}

void MyDoor::SetComponent(USceneComponent * comp) {
	component = comp;
}

void MyDoor::UpdateRotation(bool isOpening, float DeltaTime, float speed) {
	FRotator currentRot = GetRotation();
	FRotator targetRot = (isOpening) ? openRot : closedRot;
	FRotator newRot = FMath::RInterpConstantTo(currentRot, targetRot, DeltaTime, speed);
	component->SetWorldRotation(newRot);
}

FRotator MyDoor::GetRotation() {
	return component->GetComponentRotation();
}