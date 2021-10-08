// Fill out your copyright notice in the Description page of Project Settings.


#include "EndGameWidget.h"
#include "SlateCore.h"
#include "LandscapeEditor/Public/LandscapeEditorObject.h"
#include "Styling/SlateColor.h"

bool UEndGameWidget::Initialize()
{
	Super::Initialize();
	return true;
}

void UEndGameWidget::ShowEndScreen(bool GameState)
{
	if(GameState)
	{
		EndGameText->SetText(FText::FromString("WIN"));
	}
	else
	{
		EndGameText->SetText(FText::FromString("LOSE"));
	}
}



