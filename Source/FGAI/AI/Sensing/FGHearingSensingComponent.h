// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FGAI/Components/NoiseComponent.h"
#include "FGHearingSensingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FGAI_API UFGHearingSensingComponent : public UActorComponent
{
	GENERATED_BODY()

public:


public:	
	// Sets default values for this component's properties
	UFGHearingSensingComponent();
	UFUNCTION()
	void OnHear(FVector Location);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


		
};
