// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UENUM(BlueprintType)
enum class PickupStateEnum : uint8
{
	Active 	UMETA(DisplayName = "Active"),
	Picked 	UMETA(DisplayName = "Picked"),
	Stored	UMETA(DisplayName = "Stored")
};

UCLASS()
class ADVENTUREMERCHANT_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Pickup")
	void WasPicked();
	
	void WasPicked_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Pickup")
	void WasDropped();

	void WasDropped_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Pickup")
		void WasStored();

	void WasStored_Implementation();

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;
	
	//Maybe change to blueprint read&write?
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	PickupStateEnum PickupState;

};
