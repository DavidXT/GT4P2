// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPauseWidget.h"
#include "Kismet/GameplayStatics.h"

bool UMyPauseWidget::Initialize()
{
	Super::Initialize();
	ResumeButton->OnClicked.AddDynamic(this, &UMyPauseWidget::OnClickResume);
	return true;
}

void UMyPauseWidget::OnClickResume()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	//this->SetVisibility(ESlateVisibility::Hidden);
}
