// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "Components/PointLightComponent.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/Actor.h"
#include "CPP_Light_Clutter.generated.h"

class UPointLightComponent;
class UStaticMeshComponent;
class UCurveFloat;

UCLASS()
class ZOMBIEGAME_API ACPP_Light_Clutter : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ACPP_Light_Clutter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	class UTimelineComponent* CurveTimeline;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Timeline", meta = (ExposeOnSpawn = "true"))
		class UCurveFloat* CurveFloat;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Timeline", meta = (ExposeOnSpawn = "true"))
		float MaxIntensity = 10000.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Timeline", meta = (ExposeOnSpawn = "true"))
		float MinIntensity = 2500.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Timeline", meta = (ExposeOnSpawn = "true"))
		float CycleSpeed = 0.5f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Light", meta = (ExposeOnSpawn = "true"))
		FLinearColor LightColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Light", meta = (ExposeOnSpawn = "true"))
		float SourceRadius;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Light", meta = (ExposeOnSpawn = "true"))
		float SoftSourceRadius;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Light", meta = (ExposeOnSpawn = "true"))
		float SourceLength;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Light", meta = (ExposeOnSpawn = "true"))
		bool CastShadows;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Light", meta = (ExposeOnSpawn = "true"))
		UPointLightComponent* AttachedPointLightComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Light", meta = (ExposeOnSpawn = "true"))
		UStaticMeshComponent* LightClutterStaticMeshComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Mesh", meta = (ExposeOnSpawn = "true"))
		UStaticMesh* LightClutterStaticMesh;

	FOnTimelineFloat InterpFunction{};

	UFUNCTION()
		void TimelineFloatReturn(float value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};