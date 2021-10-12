// Fill out your copyright notice in the Description page of Project Settings.


#include "EndGameWidget.h"
#include "SlateCore.h"
#include "Kismet/GameplayStatics.h"
#include "Styling/SlateColor.h"

bool UEndGameWidget::Initialize()
{
	Super::Initialize();
	RestartButton->OnClicked.AddDynamic(this, &UEndGameWidget::OnClickRestart);
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

void UEndGameWidget::OnClickRestart()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}



