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
	PGameMode = GetWorld()->GetAuthGameMode<AProjet2GameMode>();
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
				}else
				{
					TimeBeforeSpawn = FMath::RandRange(1,5);
				}
			}else
			{
				TimeBeforeSpawn -= DeltaTime;
			}
		}
	}
}


void ASpawner::SpawnIA()
{
	if (AISpawn == NULL)
	{
		return;
	}
	if (Food == NULL)
	{
		return;
	}
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AActor* IaActor = GetWorld()->SpawnActor<AActor>(AISpawn, GetActorLocation(), GetActorRotation(), SpawnParams); //Cast blueprint
	AMyGameState* const MyGameState = GetWorld() != NULL ? GetWorld()->GetGameState<AMyGameState>() : NULL;
	if(MyGameState)
	{
		if(MyGameState->CheckAvailability())
		{
			AActor* Item = GetWorld()->SpawnActor<AActor>(Food, GetActorLocation(), GetActorRotation(), SpawnParams); //Cast blueprint
			MyGameState->NbFoodInRoom++;
			if(Item->IsA(AItem::StaticClass()))
			{
				static_cast<AItem*>(Item)->PickItem(IaActor);
				if(IaActor->IsA(AAICharacter::StaticClass()))
				{
					static_cast<AAICharacter*>(IaActor)->GetCharacterMovement()->MaxWalkSpeed = MaxSpeed/2;
					static_cast<AAICharacter*>(IaActor)->CurrentItem = static_cast<AItem*>(Item);
					static_cast<AAICharacter*>(IaActor)->Spawn = this;
					static_cast<AAICharacter*>(IaActor)->bHolding = true;
				}
			}
		}else{
			if(IaActor->IsA(AAICharacter::StaticClass()))
			{
				static_cast<AAICharacter*>(IaActor)->GetCharacterMovement()->MaxWalkSpeed = MaxSpeed;
				static_cast<AAICharacter*>(IaActor)->Spawn = this;
				static_cast<AAICharacter*>(IaActor)->bHolding = false;
			}
		}
	}
}

