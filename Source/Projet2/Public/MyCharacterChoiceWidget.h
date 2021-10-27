// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Projet2/Projet2Character.h"
#include "MyCharacterChoiceWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJET2_API UMyCharacterChoiceWidget : public UUserWidget
{
	GENERATED_BODY()

	public:
	virtual bool Initialize() override;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* FirstPersoButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* TwoPersoButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* ThirdPersoButton;
	
	AProjet2Character* Character;
	
	UFUNCTION()
	void OnClickFirstPerso();
	
	UFUNCTION()
	void OnClickTwoPerso();
	
	UFUNCTION()
	void OnClickThirdPerso();
	
	
};
