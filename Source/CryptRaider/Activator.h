// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Activator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UActivator : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActivator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
		float range = 400.0f;
	UPROPERTY(EditAnywhere)
		float radius = 10.0f;
	UPROPERTY(EditAnywhere)
		float holdDistance = 350.0f;
	
	UFUNCTION(BlueprintCallable)
		void Use();

	bool CheckHitResults(FHitResult& hitResult);
	void ActivateGatelock(UPrimitiveComponent * hitComponent);

	
		
};
