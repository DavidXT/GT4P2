// Fill out your copyright notice in the Description page of Project Settings.


#include <Projet2\Public\UI\MyCharacterChoiceWidget.h>
#include <Projet2\Public\Character\Projet2Character.h>
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
	/*AProjet2Character* character;
	character->TwoPerso();*/

}

void UMyCharacterChoiceWidget::OnClickThirdPerso()
{
	/*AProjet2Character* character;
	character->ThirdPerso();*/
}