// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"

UMyGameInstance::UMyGameInstance(const FObjectInitializer& ObjectInitializer) {
	static ConstructorHelpers::FClassFinder<UUserWidget> MainWidget(TEXT("/Game/Blueprint/HUDWidget"));
	if (!ensure (MainWidget.Class != nullptr)) return;

	MyWidget = MainWidget.Class;
}

void UMyGameInstance::Init() {
	
}

void UMyGameInstance::ShowWidget() {
	UUserWidget* MyHUD = CreateWidget<UUserWidget>(this, MyWidget);
	MyHUD->AddToViewport();

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(MyHUD->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}