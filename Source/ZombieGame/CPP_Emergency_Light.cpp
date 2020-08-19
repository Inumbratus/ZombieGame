// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Emergency_Light.h"
#include "Components/TimelineComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACPP_Emergency_Light::ACPP_Emergency_Light()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurveTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Timeline"));

	InterpFunction.BindUFunction(this, FName("TimelineFloatReturn"));


}

// Called when the game starts or when spawned
void ACPP_Emergency_Light::BeginPlay()
{
	Super::BeginPlay();

	

	RandomRotationOffset = UKismetMathLibrary::RandomFloatInRange(0.0f, 360.0f);
	//this->SetActorRelativeRotation(FRotator::FRotator(0.0f, RandomRotationOffset, 0.0f));
	//this->AddActorLocalRotation(FRotator::FRotator(0.0f, (RandomRotationOffset), 0.0f));

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::SanitizeFloat(RotationSpeed));

	//Check if UCurveFloat is Valid
	if (RotationCurveFloat)
	{
		//Bind Delagate

		CurveTimeline->AddInterpFloat(RotationCurveFloat, InterpFunction, FName("Alpha"));
		CurveTimeline->SetLooping(true);

		//this->AddActorLocalRotation(FRotator(0.0f, RotationsPerSecond, 0.0f));

		CurveTimeline->PlayFromStart();

		//Setting Values

	}
}

void ACPP_Emergency_Light::TimelineFloatReturn(float value)
{
	this->SetActorRotation(FRotator(0.0f, value + RandomRotationOffset, 0.0f));
}

// Called every frame
void ACPP_Emergency_Light::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//this->AddActorLocalRotation(FRotator(0.0f, (RotationsPerSecond) * DeltaTime, 0.0f));

}