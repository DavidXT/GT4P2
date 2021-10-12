// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameState.generated.h"

/**
 * 
 */
UCLASS()
class PROJET2_API AMyGameState : public AGameStateBase
{
	GENERATED_BODY()

public :
	UPROPERTY(VisibleAnywhere)
	float Score;
	
	UPROPERTY(VisibleAnywhere)
	float WinScore = 1.0f;

	UPROPERTY(VisibleAnywhere)
	bool bIsWin = false;

	UPROPERTY(VisibleAnywhere)
	bool bIsLose = false;
	
	float GetScore();
	
	void AddScore(float);
};
