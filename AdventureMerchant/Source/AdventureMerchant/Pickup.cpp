// Fill out your copyright notice in the Description page of Project Settings.

#include "AdventureMerchant.h"
#include "Pickup.h"


// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickupTransform = CreateDefaultSubobject<USceneComponent>(TEXT("PickupTransform"));
	RootComponent = PickupTransform;
	
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupMesh->SetupAttachment(RootComponent);

	PickupLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PickupLight"));
	PickupLight->SetupAttachment(RootComponent);

	PickupState = PickupStateEnum::Active;
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	PickupLight->SetIntensity(InitialLightIntensity + LightIntensityRange * cos(UGameplayStatics::GetRealTimeSeconds(GetWorld()) * LightIntensityChangeSpeed));
}

void APickup::WasPicked_Implementation()
{
	PickupLight->SetVisibility(false);
	UE_LOG(LogTemp, Log, TEXT("Default Pickup called"));
}