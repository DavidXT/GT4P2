// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Blueprint/UserWidget.h"

#include "UObject/ConstructorHelpers.h"

UMyGameInstance::UMyGameInstance(const FObjectInitializer& ObjectInitializer) {
	static ConstructorHelpers::FClassFinder<UMyUserWidget> MainWidget(TEXT("/Game/Blueprint/HUDWidget"));
	if (!ensure (MainWidget.Class != nullptr)) return;

	MyWidget = MainWidget.Class;

	static ConstructorHelpers::FClassFinder<UEndGameWidget> WidgetEndGame(TEXT("/Game/Blueprint/EndScreen"));
	if (!ensure (WidgetEndGame.Class != nullptr)) return;
		
	EndScreen = WidgetEndGame.Class;
	
}

void UMyGameInstance::Init() {

}

//Show ProgressBar and 3D Portrait HUD
void UMyGameInstance::ShowWidget() {

	
	UMyUserWidget* MyHUD = CreateWidget<UMyUserWidget>(this, MyWidget);
	MyUserWidget = MyHUD;
	MyUserWidget->AddToViewport();

	APlayerController* PlayerController = GetFirstLocalPlayerController();;
	FInputModeGameOnly const InputModeData;
	
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = false;
}

//Update ProgressBar
void UMyGameInstance::UpdateFoodBar(float NewPercent)
{
	MyUserWidget->UpdateFoodBar(NewPercent);
}

//Show EndGame Win/Lose screen
void UMyGameInstance::ShowWidgetEndGame(bool GameState)
{
	UEndGameWidget* MyHUD = CreateWidget<UEndGameWidget>(this, EndScreen);
	EndGameWidget = MyHUD;
	EndGameWidget->ShowEndScreen(GameState);
	EndGameWidget->AddToViewport();

	APlayerController* PlayerController = GetFirstLocalPlayerController();;
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(EndGameWidget->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetIgnoreMoveInput(true);
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}


