// Fill out your copyright notice in the Description page of Project Settings.


#include "Npc.h"

// Sets default values
ANpc::ANpc()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANpc::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ANpc::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	int X = this->GetActorLocation().X;
	int Y = this->GetActorLocation().Y;
	int Z = this->GetActorLocation().Z;
	this->SetActorLocation(FVector(X+10, Y, Z), false, false);

}

