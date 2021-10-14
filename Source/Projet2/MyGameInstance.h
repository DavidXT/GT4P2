// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyUserWidget.h"
#include "EndGameWidget.h"
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
	void UpdateFoodBar(float NewPercent);

	UFUNCTION(BlueprintCallable)
	void ShowWidgetEndGame(bool GameState);

	UMyUserWidget* MyUserWidget;

	UEndGameWidget* EndGameWidget;

private:
	TSubclassOf<class UMyUserWidget> MyWidget;
	TSubclassOf<class UEndGameWidget> EndScreen;
};
