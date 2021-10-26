// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

#include "AICharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Projet2/Item.h"

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
	UObject* SpawnedItem = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Blueprint/BP_Item")));
	const UBlueprint* GeneratedBPItem = Cast<UBlueprint>(SpawnedItem);
	if (!SpawnedItem)
	{
		return;
	}
	UClass* SpawnClassItem = SpawnedItem->StaticClass();
	if (SpawnClassItem == NULL)
	{
		return;
	}
	UObject* SpawnedIA = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Blueprint/BP_AIChar")));
	const UBlueprint* GeneratedBPIA = Cast<UBlueprint>(SpawnedIA);
	if (!SpawnedItem)
	{
		return;
	}
	UClass* SpawnClassIA = SpawnedIA->StaticClass();
	if (SpawnClassIA == NULL)
	{
		return;
	}
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AActor* IaActor = GetWorld()->SpawnActor<AActor>(GeneratedBPIA->GeneratedClass, GetActorLocation(), GetActorRotation(), SpawnParams); //Cast blueprint
	if(PGameMode)
	{
		if(PGameMode->CheckAvailableSpot())
		{
			AActor* Item = GetWorld()->SpawnActor<AActor>(GeneratedBPItem->GeneratedClass, GetActorLocation(), GetActorRotation(), SpawnParams); //Cast blueprint
			if(Item->IsA(AItem::StaticClass()))
			{
				static_cast<AItem*>(Item)->PickItem(IaActor);
				if(IaActor->IsA(AAICharacter::StaticClass()))
				{
					static_cast<AAICharacter*>(IaActor)->GetCharacterMovement()->MaxWalkSpeed = 300;
					static_cast<AAICharacter*>(IaActor)->CurrentItem = static_cast<AItem*>(Item);
					static_cast<AAICharacter*>(IaActor)->Spawn = this;
					static_cast<AAICharacter*>(IaActor)->bHolding = true;
				}
			}
		}else{
			if(IaActor->IsA(AAICharacter::StaticClass()))
			{
				static_cast<AAICharacter*>(IaActor)->GetCharacterMovement()->MaxWalkSpeed = 600;
				static_cast<AAICharacter*>(IaActor)->Spawn = this;
				static_cast<AAICharacter*>(IaActor)->bHolding = false;
			}
		}
	}
}

