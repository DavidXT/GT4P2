// Fill out your copyright notice in the Description page of Project Settings.


#include "EndGameWidget.h"

bool UEndGameWidget::Initialize()
{
	Super::Initialize();
	return true;
}

void UEndGameWidget::ShowEndScreen(bool GameState)
{
	if(GameState)
	{
		//EndGameTexte->SetText(FText("WIN"));
	}
	else
	{
		//EndGameTexte->SetText("LOSE");
	}
}



