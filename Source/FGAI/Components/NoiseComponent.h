// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NoiseComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNoiseEmitted, FVector, Location, float, NoiseMagnitude);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FGAI_API UNoiseComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UNoiseComponent();

	UPROPERTY(BlueprintAssignable)
	FNoiseEmitted NoiseEvent;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
	void SpawnNoise(FVector Location, float NoiseMagnitude);
};