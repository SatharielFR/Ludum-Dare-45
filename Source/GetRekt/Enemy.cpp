// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	srand(time(NULL));

	vecDirection.X = rand() % nbMaxSpeed -nbMaxSpeed/2;
	vecDirection.Y = 0;
	vecDirection.Z = rand() % nbMaxSpeed - nbMaxSpeed/2;
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	this->SetActorLocation(FVector(this->GetActorLocation().X + vecDirection.X / 2, this->GetActorLocation().Y + vecDirection.Y / 2, this->GetActorLocation().Z + vecDirection.Z/2), false, false);

	
}

