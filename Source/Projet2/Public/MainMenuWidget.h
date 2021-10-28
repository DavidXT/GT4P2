// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJET2_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual bool Initialize() override;

	UPROPERTY(meta = (BindWidget))
	class UButton* StartButton;

	UFUNCTION()
	void OnClickStart();

	UPROPERTY(meta = (BindWidget))
	class UButton* OptionsButton;

	UFUNCTION()
	void OnClickOptions();

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

	UFUNCTION()
	void OnClickQuit();
};
