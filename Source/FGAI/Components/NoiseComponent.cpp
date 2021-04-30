// Fill out your copyright notice in the Description page of Project Settings.


#include "NoiseComponent.h"
#include "FGAI/AI/Sensing/FGNoiseActor.h"



// Sets default values for this component's properties
UNoiseComponent::UNoiseComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

}


void UNoiseComponent::SpawnNoise(FVector Location)
{
	FRotator Rot;
	GetWorld()->SpawnActor<AFGNoiseActor>(Location, Rot);
	
	NoiseEvent.Broadcast(Location);
}



// Called when the game starts
void UNoiseComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UNoiseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


