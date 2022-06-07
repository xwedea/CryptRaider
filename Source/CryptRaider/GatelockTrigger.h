// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Mover.h"

#include "GatelockTrigger.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UGatelockTrigger : public UBoxComponent
{
	GENERATED_BODY()

public:
	UGatelockTrigger();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	bool CheckIfUnlocked();
	void TriggerParent();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void SetMover(UMover * NewMover);
	
	UFUNCTION(BlueprintCallable)
		void ToggleGate();
	
	
private:
	UPROPERTY(EditAnywhere)
		FName keyTag = FName(TEXT("key"));

	bool isOpen = false;
	UMover * mover;

	FRotator left_closed = FRotator(0,0,0);
	FRotator left_open = FRotator(0,90,0);
	FRotator right_closed = FRotator(0,0,0);
	FRotator right_open = FRotator(0,-90,0);
	

	void DisplayOptions();


};