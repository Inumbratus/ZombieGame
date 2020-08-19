// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPInventory.h"

// Sets default values for this component's properties
UCPPInventory::UCPPInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCPPInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCPPInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void  UCPPInventory::HealthPickup(AActor* PickupRef, float AddedHealth, bool Infinite, float PlayerHealth, float& OutHealth)
{
	if (PlayerHealth + AddedHealth <= 100)
	{
		OutHealth = PlayerHealth + AddedHealth;
	}
	else
	{
		OutHealth = 100;
	}

	if (!Infinite && PickupRef != nullptr)
	{
		PickupRef->Destroy();
	}
}

void UCPPInventory::AmmoPickup(AActor* PickupRef, int AddedAmount, bool Infinite, int MagazineSize, int MagazineAmmo, int ReserveAmmo, int MaxReserveAmmo, int& OutAmmo)
{
	if (MagazineAmmo + ReserveAmmo + AddedAmount <= MaxReserveAmmo + MagazineSize)
	{
		OutAmmo = ReserveAmmo + AddedAmount;
	}
	else
	{
		OutAmmo = MaxReserveAmmo + MagazineSize - MagazineAmmo;
	}

	if (!Infinite && PickupRef != nullptr)
	{
		PickupRef->Destroy();
	}
}

