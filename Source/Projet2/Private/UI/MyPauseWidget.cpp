// Fill out your copyright notice in the Description page of Project Settings.


#include <Projet2\Public\UI\MyPauseWidget.h>
#include "Kismet/GameplayStatics.h"

bool UMyPauseWidget::Initialize()
{
	Super::Initialize();
	ResumeButton->OnClicked.AddDynamic(this, &UMyPauseWidget::OnClickResume);
	ReturnMenuButton->OnClicked.AddDynamic(this, &UMyPauseWidget::OnClickReturnMenu);
	return true;
}

void UMyPauseWidget::OnClickResume()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	FInputModeGameOnly const InputModeData;
	PlayerController->SetInputMode(InputModeData);
	PlayerController->SetIgnoreMoveInput(false);
	PlayerController->bShowMouseCursor = false;
	
	this->RemoveFromViewport();
}

void UMyPauseWidget::OnClickReturnMenu()
{
	UGameplayStatics::OpenLevel(this, FName("MainMenu"));
}