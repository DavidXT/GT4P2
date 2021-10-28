// Fill out your copyright notice in the Description page of Project Settings.



#include "Actor/DepotZone.h"
#include "GameMode/MyGameState.h"

// Sets default values
ADepotZone::ADepotZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Collider = CreateDefaultSubobject<UBoxComponent>(FName("Collider"));
	Collider->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADepotZone::BeginPlay()
{
	Super::BeginPlay();
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ADepotZone::OnBeginOverlap);
	MyGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
}

void ADepotZone::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor->IsA(AItem::StaticClass()))
	{
		AMyGameState* const MyGameState = GetWorld() != nullptr ? GetWorld()->GetGameState<AMyGameState>() : nullptr;
		if (MyGameState != nullptr) {
			MyGameState->AddScore(static_cast<AItem*>(OtherActor)->FoodValue);
		}
		MyGameState->NbFoodInRoom--;
		OtherActor->Destroy();
	}
}

// Called every frame
void ADepotZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

