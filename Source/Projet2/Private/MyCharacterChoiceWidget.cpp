// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterChoiceWidget.h"
//#include "Kismet/GameplayStatics.h"

bool UMyCharacterChoiceWidget::Initialize()
{
	Super::Initialize();
	FirstPersoButton->OnClicked.AddDynamic(this, &UMyCharacterChoiceWidget::OnClickFirstPerso);
	TwoPersoButton->OnClicked.AddDynamic(this, &UMyCharacterChoiceWidget::OnClickTwoPerso);
	ThirdPersoButton->OnClicked.AddDynamic(this, &UMyCharacterChoiceWidget::OnClickThirdPerso);
	return true;
}

void UMyCharacterChoiceWidget::OnClickFirstPerso()
{
	
}

void UMyCharacterChoiceWidget::OnClickTwoPerso()
{
	Character->TwoPerso();
	
}

void UMyCharacterChoiceWidget::OnClickThirdPerso()
{
	Character->ThirdPerso();
}