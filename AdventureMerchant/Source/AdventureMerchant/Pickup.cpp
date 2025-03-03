// Fill out your copyright notice in the Description page of Project Settings.

#include "AdventureMerchant.h"
#include "Pickup.h"


// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;

	PickupState = PickupStateEnum::Active;
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}


void APickup::WasPicked_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("Default Pickup called"));
	PickupMesh->SetSimulatePhysics(false);
	PickupMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	PickupMesh->SetEnableGravity(false);
	PickupMesh->SetConstraintMode(EDOFMode::None);
	PickupState = PickupStateEnum::Picked;
}

void APickup::WasDropped_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("Default Drop called"));
	PickupMesh->SetSimulatePhysics(true);
	PickupMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	PickupMesh->SetEnableGravity(true);
	PickupMesh->SetConstraintMode(EDOFMode::Default);
	PickupState = PickupStateEnum::Active;

}

void APickup::WasStored_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("Default Stored called"));
	PickupMesh->SetSimulatePhysics(true);
	PickupMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	PickupMesh->SetEnableGravity(true);
	PickupMesh->SetConstraintMode(EDOFMode::Default);
	PickupState = PickupStateEnum::Stored;

}