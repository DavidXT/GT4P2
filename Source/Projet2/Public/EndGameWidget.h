// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Styling/SlateColor.h"
#include "EndGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJET2_API UEndGameWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;
	
	UPROPERTY(meta = (BindWidget))
    class UTextBlock* EndGameText;

	UPROPERTY(meta = (BindWidget))
	class UButton* RestartButton;

	UFUNCTION()
	void ShowEndScreen(bool GameState);
	
	UFUNCTION()
	void OnClickRestart();
};
