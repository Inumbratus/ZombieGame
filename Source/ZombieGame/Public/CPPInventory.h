// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPPInventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIEGAME_API UCPPInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPPInventory();

	UFUNCTION(BlueprintCallable, Category = "HealthPickup")
		virtual	void HealthPickup(AActor* PickupRef, float AddedHealth, bool Infinite, float PlayerHealth, float& OutHealth);

	UFUNCTION(BlueprintCallable, Category = "AmmoPickup")
		virtual	void AmmoPickup(AActor* PickupRef, int AddedAmount, bool Infinite, int MagazineSize, int MagazineAmmo, int ReserveAmmo, int MaxReserveAmmo, int& OutAmmo);



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
