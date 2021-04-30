// Fill out your copyright notice in the Description page of Project Settings.


#include "FGHearingSensingComponent.h"
#include "FGAI/Components/NoiseComponent.h"

UFGHearingSensingComponent::UFGHearingSensingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UFGHearingSensingComponent::OnHear(FVector Location)
{
	UE_LOG(LogTemp, Warning, TEXT("dsadsa"));
	
}


// Called when the game starts
void UFGHearingSensingComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();
	UNoiseComponent* NoiseComponent = Owner->FindComponentByClass<UNoiseComponent>();

	if(NoiseComponent != NULL)
	{
		NoiseComponent->NoiseEvent.AddDynamic(this, &UFGHearingSensingComponent::OnHear);

	}
}


// Called every frame
void UFGHearingSensingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
