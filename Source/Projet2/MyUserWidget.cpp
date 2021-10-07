// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"

bool UMyUserWidget::Initialize()
{
	Super::Initialize();
	return false;
}

void UMyUserWidget::UpdateFoodBar(float NewPercent)
{
	FoodBar->Percent = NewPercent;
}

//void UMyUserWidget::Tick(FGeometry MyGeometry, float InDeltaTime)
//{
//	Super::Tick(MyGeometry,InDeltaTime);
//	AMyGameState* const MyGameState = GetWorld() != NULL ? GetWorld()->GetGameState<AMyGameState>() : NULL;
//	if (MyGameState != NULL) {
//		FoodBarPercent = MyGameState->Score / 5;
//	}
//	UpdateFoodBar(FoodBarPercent);
//}
