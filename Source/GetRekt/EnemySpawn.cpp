// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawn.h"

// Sets default values
AEnemySpawn::AEnemySpawn()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawn::BeginPlay()
{
	Super::BeginPlay();

	//fScale = 1;
	srand(time(NULL));
}

// Called every frame
void AEnemySpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	fLastTime += DeltaTime;
	if (fLastTime >= fAwaitSpawn)// > 0)
	{
		fLastTime = 0;
		FVector vecLocation = FVector(GetActorLocation().X + (SCREEN_SIZE * cos(rand() % RANGE), GetActorLocation().Y, GetActorLocation().Z + (SCREEN_SIZE * cos(rand() % RANGE))));
		goEnemySpawned = GetWorld()->SpawnActor<AEnemy>(vecLocation, FRotator::ZeroRotator);
		//goEnemySpawned->fScale = fscale;
	}
}

