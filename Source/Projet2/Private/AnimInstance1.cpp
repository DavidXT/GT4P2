// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance1.h"

#include "Projet2/Projet2Character.h"


UAnimInstance1::UAnimInstance1()
{
	Speed = 0.0;
	bIsHoldingItem = false;
}



void UAnimInstance1::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	AActor* OwningActor = GetOwningActor();

	if(OwningActor)
	{
		Speed = OwningActor->GetVelocity().Size();
	}

	if(OwningActor->IsA(AProjet2Character::StaticClass()))
	{
		bIsHoldingItem = ((AProjet2Character*)OwningActor)->bIsHoldingItem;
	}
	
}


