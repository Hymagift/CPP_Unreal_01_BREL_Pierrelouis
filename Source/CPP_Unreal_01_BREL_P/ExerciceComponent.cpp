

#include "ExerciceComponent.h"

UExerciceComponent::UExerciceComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	TargetScale = 1.0f;
	ScaleSpeed = 0.1f;
	BaseScale = FVector(0.0f, 0.0f, 0.0f);
	Oscille = true;
}


void UExerciceComponent::BeginPlay()
{
	Super::BeginPlay();

    AActor* Owner = GetOwner();
    if (Owner)
	{
		BaseScale = Owner->GetActorScale3D();
	}
}




void UExerciceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Oscille == false)
	{
		return;
	}
	AActor* Owner = GetOwner();

	float Alpha = ScaleSpeed * DeltaTime;

	if (Alpha >= 0.0f)
	{
		FVector ScalingUp = FMath::Lerp(BaseScale, TargetScale, Alpha);
		Owner->SetActorScale3D(ScalingUp);
	}
	else if (Alpha <= 1.0f)
	{
		FVector ScalingDown = FMath::Lerp(TargetScale, BaseScale, Alpha);
		Owner->SetActorScale3D(ScalingDown);
	}

}

float UExerciceComponent::StartOscillation()
{
	Oscille = true;
}

float UExerciceComponent::StopOscillation()
{
	Oscille = false;
}

