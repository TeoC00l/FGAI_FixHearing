
#include "FGHearingSensingComponent.h"
#include "EngineUtils.h"
#include "FGAI/FGCharacter.h"
#include "FGAI/Components/NoiseComponent.h"

UFGHearingSensingComponent::UFGHearingSensingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UFGHearingSensingComponent::OnHear(FVector Location, float NoiseMagnitude)
{
	float DistanceSqr = FVector::DistSquared(GetOwner()->GetActorLocation(), Location);

	UE_LOG(LogTemp, Warning, TEXT("DS: %f, NM: %f"), DistanceSqr, NoiseMagnitude);
	NoiseMagnitude *= NoiseMagnitude;
	if(DistanceSqr < NoiseMagnitude )
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("SOMEONE HEARD YOU"));
	}
	
}


// Called when the game starts
void UFGHearingSensingComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();

	for(TActorIterator<AFGCharacter> NoiseItr(GetWorld()); NoiseItr; ++NoiseItr)
	{
		AFGCharacter* Char = *NoiseItr;

		UActorComponent* Act = (Char->FindComponentByClass<UNoiseComponent>());
		
		if(Act!=nullptr)
		{
			UNoiseComponent* NoiseComponent = Cast<UNoiseComponent>(Act);
			NoiseComponent->NoiseEvent.AddDynamic(this, &UFGHearingSensingComponent::OnHear);

		}
	}
}


// Called every frame
void UFGHearingSensingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
