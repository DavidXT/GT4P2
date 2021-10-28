// Fill out your copyright notice in the Description page of Project Settings.


#include <Projet2\Public\UI\MainMenuWidget.h>
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

bool UMainMenuWidget::Initialize()
{
	Super::Initialize();
	StartButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnClickStart);
	QuitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnClickQuit);
	return true;
}

void UMainMenuWidget::OnClickStart()
{
	UGameplayStatics::OpenLevel(this, FName("Game"));
}

void UMainMenuWidget::OnClickQuit()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
}