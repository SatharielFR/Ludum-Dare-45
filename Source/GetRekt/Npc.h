// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Npc.generated.h"

UCLASS()

class GETREKT_API ANpc : public AActor
{
	GENERATED_BODY()

		
private:
	//current direction of the NPC
	FVector vCurrentDirection;
	 
	
public:	
	// Sets default values for this actor's properties
	ANpc();
	FVector ChangeNpcDirection(FVector currentDirection);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

};
