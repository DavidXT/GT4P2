// Copyright Epic Games, Inc. All Rights Reserved.

#include "Projet2GameMode.h"
#include "Projet2Character.h"
#include "Algo/ForEach.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AProjet2GameMode::AProjet2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AProjet2GameMode::BeginPlay()
{
	Super::BeginPlay();
	MyGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	if (GetWorld()->GetMapName() == "UEDPIE_0_MainMenu") {
		MyGameInstance->ShowWidgetMainMenu();
	}
	if (GetWorld()->GetMapName() == "UEDPIE_0_Game") {
		MyGameInstance->ShowWidget();
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetActor::StaticClass(), TargetActors);
		if (Food == nullptr)
		{
			return;
		}
		const int RandInt = FMath::RandRange(0, TargetActors.Num() - 1);
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		GetWorld()->SpawnActor<AActor>(Food, TargetActors[RandInt]->GetActorLocation(), TargetActors[RandInt]->GetActorRotation(), SpawnParams); //Cast blueprint
		static_cast<ATargetActor*>(TargetActors[RandInt])->bHasItem = true;
	}
}

bool AProjet2GameMode::CheckAvailableSpot()
{
	for (int i = 0; i < TargetActors.Num(); i++)
	{
		if(TargetActors[i]->IsA(ATargetActor::StaticClass()))
		{
			if(static_cast<ATargetActor*>(TargetActors[i])->bHasItem == false)
			{
				return true;
			}
		}
	}
	return false;
}


