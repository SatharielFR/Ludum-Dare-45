// Fill out your copyright notice in the Description page of Project Settings.


#include "Npc.h"
#include "Components/BoxComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/ConstructorHelpers.h"
#include "UObject/UObjectBaseUtility.h"


// Sets default values
ANpc::ANpc() : iVitesseMax(10), vCurrentDirection(FVector(10, 0, 0))
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// create trigger capsule
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	TriggerBox->InitBoxExtent(FVector(50, 50, 50));
	TriggerBox->SetBoxExtent(FVector(50, 50, 50), true);
	TriggerBox->SetCollisionProfileName(TEXT("Trigger"));
	TriggerBox->SetupAttachment(RootComponent);

	//TriggerBox->AddToRoot();
	/*
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	RootComponent = MyMesh;*/


}


// Called when the game starts or when spawned
void ANpc::BeginPlay()
{
	Super::BeginPlay();
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("OnOverlapBegin"));
	// declare overlap events
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ANpc::OnOverlapBegin);
	//TriggerBox->OnComponentHit.AddDynamic(this, &ANpc::OnComponentHit);    // set up a notification for when this component overlaps something




}

// Called every frame
void ANpc::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	int X = this->GetActorLocation().X + this->getCurrentDirection().X;
	int Y = this->GetActorLocation().Y + this->getCurrentDirection().Y;
	int Z = this->GetActorLocation().Z + this->getCurrentDirection().Z;

	this->SetActorLocation(FVector(X, Y, Z), false, false);


}

void ANpc::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	this->ChangeNpcDirection();

}


// method used to get a new random direction 
void ANpc::ChangeNpcDirection()
{

	FVector nextDirection = FVector(0, 0, 0);

	if (this->getCurrentDirection().X != 0) {
		if (this->getCurrentDirection().X > 0) {
			this->SetActorLocation(FVector(this->GetActorLocation().X - 10, this->GetActorLocation().Y, this->GetActorLocation().Z));
			int iRandom = rand() % 2;
			switch (iRandom) {
			case 0:
				nextDirection = FVector(-this->getVitesseMax(), 0, 0);
				break;
			case 1:
				nextDirection = FVector(0, 0, this->getVitesseMax());
				break;
			case 2:
				nextDirection = FVector(0, 0, -this->getVitesseMax());
				break;
			default:
				nextDirection = FVector(0, 0, 0);
				break;
			}
		}
		else {
			this->SetActorLocation(FVector(this->GetActorLocation().X + 10, this->GetActorLocation().Y, this->GetActorLocation().Z));
			int iRandom = rand() % 2;
			switch (iRandom) {
			case 0:
				nextDirection = FVector(this->getVitesseMax(), 0, 0);
				break;
			case 1:
				nextDirection = FVector(0, 0, this->getVitesseMax());
				break;
			case 2:
				nextDirection = FVector(0, 0, -this->getVitesseMax());
				break;
			default:
				nextDirection = FVector(0, 0, 0);
				break;
			}
		}
	}
	else {
		if (this->getCurrentDirection().Z > 0) {
			this->SetActorLocation(FVector(this->GetActorLocation().X, this->GetActorLocation().Y, this->GetActorLocation().Z - 10));
			int iRandom = rand() % 2;
			switch (iRandom) {
			case 0:
				nextDirection = FVector(this->getVitesseMax(), 0, 0);
				break;
			case 1:
				nextDirection = FVector(0, 0, -this->getVitesseMax());
				break;
			case 2:
				nextDirection = FVector(this->getVitesseMax(), 0, 0);
				break;
			default:
				nextDirection = FVector(0, 0, 0);
				break;
			}
		}
		else {
			this->SetActorLocation(FVector(this->GetActorLocation().X, this->GetActorLocation().Y, this->GetActorLocation().Z + 10));
			int iRandom = rand() % 2;
			switch (iRandom) {
			case 0:
				nextDirection = FVector(this->getVitesseMax(), 0, 0);
				break;
			case 1:
				nextDirection = FVector(0, 0, this->getVitesseMax());
				break;
			case 2:
				nextDirection = FVector(this->getVitesseMax(), 0, 0);
				break;
			default:
				nextDirection = FVector(0, 0, 0);
				break;
			}
		}
	}

	this->setCurrentDirection(nextDirection);
}

