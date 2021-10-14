// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameState.h"

#include "MyGameInstance.h"

float AMyGameState::GetScore()
{
	return Score;
}

void AMyGameState::AddScore(float S)
{
	Score += S;
	UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	if(MyGameInstance)
	{
		MyGameInstance->UpdateFoodBar(Score/WinScore);
		if(Score >= WinScore)
		{
			bIsWin = true;
			MyGameInstance->ShowWidgetEndGame(true);
		}
	}
}

void AMyGameState::Lose()
{
	UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	if(MyGameInstance)
	{
		bIsLose = true;
		MyGameInstance->ShowWidgetEndGame(false);
	}
}
