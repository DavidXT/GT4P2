// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Blueprint/UserWidget.h"

#include "UObject/ConstructorHelpers.h"

UMyGameInstance::UMyGameInstance(const FObjectInitializer& ObjectInitializer) {
	static ConstructorHelpers::FClassFinder<UMyUserWidget> MainWidget(TEXT("/Game/Blueprint/HUDWidget"));
	if (!ensure (MainWidget.Class != nullptr)) return;

	MyWidget = MainWidget.Class;
}

void UMyGameInstance::Init() {
	
}

void UMyGameInstance::ShowWidget() {
	UMyUserWidget* MyHUD = CreateWidget<UMyUserWidget>(this, MyWidget);
	MyUserWidget = MyHUD;
	MyUserWidget->AddToViewport();
}

void UMyGameInstance::UpdateFoodBar(float NewPercent)
{
	MyUserWidget->UpdateFoodBar(NewPercent);
}
