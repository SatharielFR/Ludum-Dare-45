// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Npc.generated.h"


UCLASS()

class GETREKT_API ANpc : public AActor
{
	GENERATED_BODY()

		
private:
	//current direction of the NPC
	FVector vCurrentDirection;
	int iVitesseMax;
	 
	
public:	
	// Sets default values for this actor's properties
	ANpc();
	void ChangeNpcDirection();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// create mesh 
	UPROPERTY(VisibleAnywhere, Category = "MyMesh")
		class UStaticMeshComponent* MyMesh;

	// create trigger capsule
	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
		class UBoxComponent* TriggerBox;
	

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//get
	FVector getCurrentDirection() { return vCurrentDirection; };
	int getVitesseMax() { return iVitesseMax; }

	//set
	void setCurrentDirection(FVector vNewDirection) { vCurrentDirection = vNewDirection; }
	void setVitesseMax(int iNewVitesse) { iVitesseMax = iNewVitesse; }


	

};
