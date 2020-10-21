// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FrameRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
	
}

// Called every frame

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    Rotate();
    Move();
}
void APawnTurret::CheckFireCondition() 
{
    // If player == null || is Dead THEN BAIL!!

    // If Player IS in range THEN FIRE!!

    UE_LOG(logTemp, Warning, TEXT("Fire Condition, check!"));
}
