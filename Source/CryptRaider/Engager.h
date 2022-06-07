// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UEngager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEngager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	bool CheckHitResults(FHitResult& hitResult);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
		void Engage();

private:
	UPROPERTY(EditAnywhere)
		float range = 400.0f;
	UPROPERTY(EditAnywhere)
		float radius = 10.0f;
	UPROPERTY(EditAnywhere)
		float holdDistance = 350.0f;
		
};
