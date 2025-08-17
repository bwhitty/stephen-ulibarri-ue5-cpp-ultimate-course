// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "Slash/DebugMacros.h"

#define THIRTY 30

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	int32 AvgInt = Avg<int32>(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("Avg of 1 and 3: %d"), AvgInt);

	float AvgFloat = Avg<float>(3.45f, 7.86f);
	UE_LOG(LogTemp, Warning, TEXT("Avg of 1 and 3: %f"), AvgFloat);
	
	// SetActorLocation(FVector(0.f, 0.f, 50.f));
	// SetActorRotation(FRotator(0.f, 45.f, 0.f));

	// FVector Location = GetActorLocation();
	// FVector ForwardVector = GetActorForwardVector();
	//
	// DRAW_SPHERE(Location);
	// DRAW_VECTOR(Location, Location + ForwardVector * 100.f);
}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	// float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	//
	// AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));
	
	//
	// // movement rate in units of (cm/s)
	// float MovementRate = 50.f;
	// float RotationRate = 45.f;
	//
	// // MovementRate * DeltaTime (cm/s) * (s/frame) = (cm/frame)
	// AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
	// AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));
	// DRAW_SPHERE_SINGLE_FRAME(GetActorLocation());
	// DRAW_VECTOR_SINGLE_FRAME(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

	// FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	// DRAW_POINT_SINGLE_FRAME(AvgVector);
}

