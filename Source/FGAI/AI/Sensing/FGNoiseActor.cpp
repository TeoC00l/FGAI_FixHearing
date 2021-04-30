// Fill out your copyright notice in the Description page of Project Settings.


#include "FGNoiseActor.h"

#include "DrawDebugHelpers.h"

// Sets default values
AFGNoiseActor::AFGNoiseActor()
{
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootComp;
	PrimaryActorTick.bCanEverTick = true;

}

void AFGNoiseActor::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(2.f);
	DrawDebugSphere(GetWorld(), GetActorLocation(), Radius, 50, FColor::Green,false,2.f,0, 1.f);

}

void AFGNoiseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

