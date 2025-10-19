// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ExerciceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_UNREAL_01_BREL_P_API UExerciceComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UExerciceComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BluePrintCallable, Category = "Scale")
	float StartOscillation();
	float StopOscillation();


private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float TargetScale;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Scale", meta = (AllowPrivateAccess = "true"))
	float ScaleSpeed;

	FVector BaseScale;

	bool Oscille;
};
