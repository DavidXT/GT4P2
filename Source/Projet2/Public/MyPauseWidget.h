// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MyPauseWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJET2_API UMyPauseWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* ResumeButton;
	
	UFUNCTION()
	void OnClickResume();
	
};
