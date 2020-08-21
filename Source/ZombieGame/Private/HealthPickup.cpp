// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPickup.h"

// Sets default values for this component's properties
UHealthPickup::UHealthPickup()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthPickup::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthPickup::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthPickup::HealthPickup(float PlayerHealth, float HealthAmount, bool infinite, AActor* SelfRef, float& ReturnValue)
{
	if (PlayerHealth < 100) 
	{
		ReturnValue = PlayerHealth + HealthAmount;
	}
	
	if (PlayerHealth >= 100) 
	{
		ReturnValue = 100;
	}
	
	if (!infinite && SelfRef != nullptr) 
	{
		SelfRef->Destroy();
	}
}

