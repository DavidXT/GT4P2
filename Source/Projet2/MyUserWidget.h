// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "MyGameState.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJET2_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize();


	UPROPERTY(meta = (BindWidget))
	class UProgressBar* FoodBar;

	UFUNCTION()
		void UpdateFoodBar();
	
};
