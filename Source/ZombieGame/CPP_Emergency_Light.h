// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "Components/SpotLightComponent.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/Actor.h"
#include "CPP_Emergency_Light.generated.h"

class UCurveFloat;
class USpotLightComponent;
class UStaticMesh;
class UTimelineComponent;

UCLASS()
class ZOMBIEGAME_API ACPP_Emergency_Light : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ACPP_Emergency_Light();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FRotator* Rotator;

	class UTimelineComponent* CurveTimeline;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Rotation", meta = (ExposeOnSpawn = "true"))
	class UCurveFloat* RotationCurveFloat;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Rotation", meta = (ExposeOnSpawn = "true"))
	float RotationSpeed = 1.0f;

	UPROPERTY()
	float RandomRotationOffset = 0.0f;

	//Delegate Declaration, Bound to TimelineFloatReturn(float value)

	FOnTimelineFloat InterpFunction{};

	UFUNCTION()
		void TimelineFloatReturn(float value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
