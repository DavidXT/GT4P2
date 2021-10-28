// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MyGameInstance.h"

#include "Blueprint/UserWidget.h"

#include "UObject/ConstructorHelpers.h"

UMyGameInstance::UMyGameInstance(const FObjectInitializer& ObjectInitializer) {
	static ConstructorHelpers::FClassFinder<UMyUserWidget> MainWidget(TEXT("/Game/Blueprint/HUDWidget"));
	if (!ensure (MainWidget.Class != nullptr)) return;

	MyWidget = MainWidget.Class;

	static ConstructorHelpers::FClassFinder<UEndGameWidget> WidgetEndGame(TEXT("/Game/Blueprint/EndScreen"));
	if (!ensure (WidgetEndGame.Class != nullptr)) return;
		
	EndScreen = WidgetEndGame.Class;
	
	static ConstructorHelpers::FClassFinder<UMainMenuWidget> WidgetMainMenu(TEXT("/Game/Blueprint/MainMenuWidget"));
	if (!ensure(WidgetMainMenu.Class != nullptr)) return;

	MainMenuScreen = WidgetMainMenu.Class;

	static ConstructorHelpers::FClassFinder<UMyPauseWidget> PauseGame(TEXT("/Game/Blueprint/MenuPause"));
	if (!ensure (PauseGame.Class != nullptr)) return;
		
	MPause = PauseGame.Class;
}

void UMyGameInstance::Init() {

}

//Show ProgressBar and 3D Portrait HUD
void UMyGameInstance::ShowWidget() {

	
	UMyUserWidget* MyHUD = CreateWidget<UMyUserWidget>(this, MyWidget);
	MyUserWidget = MyHUD;
	MyUserWidget->AddToViewport();

	APlayerController* PlayerController = GetFirstLocalPlayerController();
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

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(EndGameWidget->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetIgnoreMoveInput(true);
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}

void UMyGameInstance::ShowWidgetMainMenu()
{
	UMainMenuWidget* MyHUD = CreateWidget<UMainMenuWidget>(this, MainMenuScreen);
	MainMenuWidget = MyHUD;
	MainMenuWidget->AddToViewport();
	
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(MainMenuWidget->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetIgnoreMoveInput(true);
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}


void UMyGameInstance::ClickResume()
{
	UMyPauseWidget* MyHUD = CreateWidget<UMyPauseWidget>(this, MPause);
	PauseWidget = MyHUD;
	PauseWidget->AddToViewport();

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(PauseWidget->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetIgnoreMoveInput(true);
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}



