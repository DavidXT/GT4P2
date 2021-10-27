// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

bool UMainMenuWidget::Initialize()
{
	Super::Initialize();
	StartButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnClickStart);
	OptionsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnClickOptions);
	QuitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnClickQuit);
	return true;
}

void UMainMenuWidget::OnClickStart()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void UMainMenuWidget::OnClickOptions()
{

}

void UMainMenuWidget::OnClickQuit()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
}