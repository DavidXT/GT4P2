// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UI/MyUserWidget.h"
#include "UI/EndGameWidget.h"
#include "UI/MainMenuWidget.h"
#include "UI/MyCharacterChoiceWidget.h"
#include "UI/MyPauseWidget.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJET2_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UMyGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init();

	UFUNCTION(BlueprintCallable)
	void ShowWidget();
	
	UFUNCTION(BlueprintCallable)
	void ShowWidgetMainMenu();

	UFUNCTION(BlueprintCallable)
	void ClickResume();

	UFUNCTION(BlueprintCallable)
    void CheckPerso();

	UFUNCTION(BlueprintCallable)
	void UpdateFoodBar(float NewPercent);

	UFUNCTION(BlueprintCallable)
	void ShowWidgetEndGame(bool GameState);

	UMyUserWidget* MyUserWidget;
	UMainMenuWidget* MainMenuWidget;
	UMyPauseWidget* PauseWidget;
	UEndGameWidget* EndGameWidget;
	UMyCharacterChoiceWidget* ChoicePersoWidget;
	

private:
	TSubclassOf<class UMyUserWidget> MyWidget;
	TSubclassOf<class UEndGameWidget> EndScreen;
	TSubclassOf<class UMainMenuWidget> MainMenuScreen;
	TSubclassOf<class UMyPauseWidget> MPause;
	TSubclassOf<class UMyCharacterChoiceWidget> ChoicePerso;
};
