// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Spawner.h"
#include "IA/AICharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Actor/Item.h"
#include "GameMode/MyGameState.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	MyGameState = GetWorld() != nullptr ? GetWorld()->GetGameState<AMyGameState>() : nullptr;
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(NbIA <= 0)
	{
		SpawnIA();
		TimeBeforeSpawn = FMath::RandRange(1,5);
		NbIA++;
	}else
	{
		if(NbIA < MaxNbIA)
		{
			if(TimeBeforeSpawn <= 0)
			{
				SpawnIA();
				NbIA++;
				if(NbIA == 2)
				{
					TimeBeforeSpawn = 60;
					bLastIA = true;
				}else
				{
					TimeBeforeSpawn = FMath::RandRange(1,5);
				}
			}else
			{
				if(NbIA == 1 && bLastIA)
				{
					TimeBeforeSpawn = FMath::RandRange(1,5);
					bLastIA = false;
				}
				TimeBeforeSpawn -= DeltaTime;
			}
		}
	}
}


void ASpawner::SpawnIA()
{
	if (AISpawn == nullptr)
	{
		return;
	}
	if (Food == nullptr)
	{
		return;
	}
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AActor* IaActor = GetWorld()->SpawnActor<AActor>(AISpawn, GetActorLocation(), GetActorRotation(), SpawnParams); //Cast blueprint
	if(MyGameState)
	{
		if(MyGameState->CheckAvailability())
		{
			//AddFood to player if number of food is not enough
			AActor* Item = GetWorld()->SpawnActor<AActor>(Food, GetActorLocation(), GetActorRotation(), SpawnParams); //Cast blueprint
			MyGameState->NbFoodInRoom++;
			if(Item != nullptr && Item->IsA(AItem::StaticClass()))
			{
				AItem* SpawnedItem = static_cast<AItem*>(Item);
				if(IaActor != nullptr && IaActor->IsA(AAICharacter::StaticClass()))
				{
					AAICharacter* SpawnedActor = static_cast<AAICharacter*>(IaActor);
					SpawnedItem->PickItem(IaActor);
					SpawnedActor->GetCharacterMovement()->MaxWalkSpeed = MaxSpeed/2;
					SpawnedActor->Spawn = this;
				}
			}
		}else{
			//Don't had food to player if enough food
			if(IaActor != nullptr && IaActor->IsA(AAICharacter::StaticClass()))
			{
				AAICharacter* SpawnedActor = static_cast<AAICharacter*>(IaActor);
				SpawnedActor->GetCharacterMovement()->MaxWalkSpeed = MaxSpeed;
				SpawnedActor->Spawn = this;
				SpawnedActor->bHolding = false;
			}
		}

	}
}

