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
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	//Light Effect Variables
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup|LightEffect")
	float InitialLightIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup|LightEffect")
	float LightIntensityRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup|LightEffect", meta = (ClampMin = "0.1"))
	float LightIntensityChangeSpeed = 1.0f;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Pickup")
	void WasPicked();
	
	void WasPicked_Implementation();

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* PickupTransform;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UPointLightComponent* PickupLight;

	//Maybe change to blueprint read&write?
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	PickupStateEnum PickupState;

};
