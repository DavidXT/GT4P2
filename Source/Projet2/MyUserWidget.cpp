// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"

#include "MyGameInstance.h"

bool UMyUserWidget::Initialize()
{
	Super::Initialize();
	return true;
}

void UMyUserWidget::UpdateFoodBar(float NewPercent)
{
	FoodBar->SetPercent(NewPercent);
}

