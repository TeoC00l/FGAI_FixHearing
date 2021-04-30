// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FGNoiseActor.generated.h"


UCLASS()
class FGAI_API AFGNoiseActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* RootComp;

	UPROPERTY(EditAnywhere)
	float Radius = 600.f;
	
public:	
	AFGNoiseActor();


protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
