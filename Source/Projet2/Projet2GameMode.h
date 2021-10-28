// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TargetActor.h"
#include "MyGameInstance.h"
#include "Projet2GameMode.generated.h"

UCLASS(minimalapi)
class AProjet2GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AProjet2GameMode();

	UPROPERTY(EditAnywhere, Category=Target)
	TArray<AActor*> TargetActors;

	UPROPERTY(EditAnywhere)
	class UClass* Food;
	
	UPROPERTY(EditAnywhere)
    class UWorld* MainMenu;
    	
    UPROPERTY(EditAnywhere)
    class UWorld* MainGame;

	UMyGameInstance* MyGameInstance;
	
	UPROPERTY(EditAnywhere)
	bool bIsPlaying;

	UFUNCTION()
	bool CheckAvailableSpot();

protected:
	virtual void BeginPlay() override;

};



