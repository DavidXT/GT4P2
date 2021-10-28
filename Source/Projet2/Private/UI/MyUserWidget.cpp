// Fill out your copyright notice in the Description page of Project Settings.


#include <Projet2\Public\UI\MyUserWidget.h>
#include <Projet2\Public\GameMode\MyGameInstance.h>

bool UMyUserWidget::Initialize()
{
	Super::Initialize();
	return true;
}

void UMyUserWidget::UpdateFoodBar(float NewPercent)
{
	FoodBar->SetPercent(NewPercent);
}

