// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <GetRekt\Enemy.h>
#include <time.h>
#include <math.h>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawn.generated.h"

#define RANGE 360*PI/180
#define SCREEN_SIZE 1950



UCLASS()
class GETREKT_API AEnemySpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawn();

	float fLastTime = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float fAwaitSpawn =2;
	AEnemy* goEnemySpawned;
	//float fScale;
};
