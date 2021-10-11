// Copyright Epic Games, Inc. All Rights Reserved.

#include "Projet2GameMode.h"
#include "Projet2Character.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AProjet2GameMode::AProjet2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AProjet2GameMode::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetActor::StaticClass(), TargetActors);
	UObject* SpawnedItem = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/Blueprint/BP_Item")));
	UBlueprint* GeneratedBP = Cast<UBlueprint>(SpawnedItem);
	if (!SpawnedItem)
	{
		return;
	}
	UClass* SpawnClass = SpawnedItem->StaticClass();
	if (SpawnClass == NULL)
	{
		return;
	}
	int randInt = FMath::RandRange(0,TargetActors.Num()-1);
	GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,FString::FromInt(randInt));
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,FString(TargetActors[randInt]->GetActorLocation().ToString()));
	GetWorld()->SpawnActor<AActor>(GeneratedBP->GeneratedClass, TargetActors[randInt]->GetActorLocation(), TargetActors[randInt]->GetActorRotation(), SpawnParams); //Cast blueprint
	((ATargetActor*)TargetActors[randInt])->bHasItem = true;
}
