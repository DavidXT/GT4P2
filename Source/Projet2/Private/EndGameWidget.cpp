// Fill out your copyright notice in the Description page of Project Settings.


#include "EndGameWidget.h"
#include "Kismet/GameplayStatics.h"

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
		EndGameText->SetColorAndOpacity(FSlateColor(FLinearColor::Green));
	}
	else
	{
		EndGameText->SetText(FText::FromString("LOSE"));
		EndGameText->SetColorAndOpacity(FSlateColor(FLinearColor::Red));
	}
}

void UEndGameWidget::OnClickRestart()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}



