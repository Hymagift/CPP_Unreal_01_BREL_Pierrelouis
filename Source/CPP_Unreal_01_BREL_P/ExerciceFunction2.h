// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ExerciceFunction2.generated.h"

/**
 * 
 */
UCLASS()
class CPP_UNREAL_01_BREL_P_API UExerciceFunction2 : public UObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Debug")
	static void PrintMessage(const FString& Message);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	static void TeleportActorTo(AActor* ActorToTeleport, AActor* TargetActor);

	UFUNCTION(BlueprintPure, Category = "Vector")
	static FVector FindShortestVector(const TArray<FVector>& Vectors);

};
