// Fill out your copyright notice in the Description page of Project Settings.


#include "ExerciceFunction2.h"

void UExerciceFunction2::PrintMessage(const FString& Message)
{
	UE_LOG(LogTemp, Log, TEXT("%s"), Message);
}

void UExerciceFunction2::TeleportActorTo(AActor* ActorToTeleport, AActor* TargetActor)
{
	FVector ActorLocation = TargetActor->GetActorLocation();
	ActorToTeleport->SetActorLocation(ActorLocation);
}

FVector UExerciceFunction2::FindShortestVector(const TArray<FVector>& Vectors)
{
	if (Vectors.Num() == 0)
	{
		return FVector::ZeroVector;
	}

	FVector ShortestVector = Vectors[0];
	float ShortestVectorLenght = ShortestVector.X + ShortestVector.Y + ShortestVector.Z;

	while (Vectors.Num() > 1)
	{
		for (int i = 1; i < Vectors.Num(); i++)
		{	
			FVector NextVector = Vectors[i];
			float NextVectorLenght = NextVector.X + NextVector.Y + NextVector.Z;
			if (NextVectorLenght < ShortestVectorLenght)
			{
				ShortestVector = Vectors[i];
			}
		}
	}
	return ShortestVector;

}
