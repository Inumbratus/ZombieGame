// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Light_Clutter.h"
#include "Components/TimelineComponent.h"
#include "Components/PointLightComponent.h"
#include "Engine/StaticMesh.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACPP_Light_Clutter::ACPP_Light_Clutter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initialise Static Mesh
	LightClutterStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	LightClutterStaticMeshComponent->SetStaticMesh(LightClutterStaticMesh);

	//Initialise Light
	AttachedPointLightComponent = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point Light"));

	//Initialise Curve
	CurveTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Timeline"));
	InterpFunction.BindUFunction(this, FName("TimelineFloatReturn"));
	
}

// Called when the game starts or when spawned
void ACPP_Light_Clutter::BeginPlay()
{
	Super::BeginPlay();

	AttachedPointLightComponent->SetLightColor(LightColor);
	AttachedPointLightComponent->SetSourceLength(SourceLength);
	AttachedPointLightComponent->SetSoftSourceRadius(SoftSourceRadius);
	AttachedPointLightComponent->SetCastShadows(CastShadows);

	//Check if UCurve is Valid
	
	if (CurveFloat)
	{

		CurveTimeline->AddInterpFloat(CurveFloat, InterpFunction, FName("Alpha"));
		CurveTimeline->SetLooping(true);
		CurveTimeline->PlayFromStart();
	}


}

void ACPP_Light_Clutter::TimelineFloatReturn(float value)
{
	AttachedPointLightComponent->SetIntensity((value * (MaxIntensity-MinIntensity)) + MinIntensity);
}

// Called every frame
void ACPP_Light_Clutter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

