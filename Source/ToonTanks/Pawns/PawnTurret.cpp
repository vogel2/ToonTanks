// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned 
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
	
}

// Called every frame

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void APawnTurret::CheckFireCondition() 
{
    // If player == null || is Dead THEN BAIL!!
    if(!PlayerPawn)
    {
        return;
    }
    // If Player IS in range THEN FIRE!!
    if(ReturnDistanceToPlayer() <= FireRange)
    {
        // FIRE!!!
        UE_LOG(LogTemp, Warning, TEXT("Fire Condition, check!"));
    }

    
}

float APawnTurret::ReturnDistanceToPlayer() 
{
    if(!PlayerPawn)
    {
        return 0.f;
    }

    float Distance = FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
    return Distance;
}