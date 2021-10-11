// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TargetActor.h"
#include "Projet2GameMode.generated.h"

UCLASS(minimalapi)
class AProjet2GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AProjet2GameMode();

	UPROPERTY(EditAnywhere, Category=Target)
	TArray<AActor*> TargetActors;

protected:
	virtual void BeginPlay() override;
};



