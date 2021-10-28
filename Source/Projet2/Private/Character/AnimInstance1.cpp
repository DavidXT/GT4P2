// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AnimInstance1.h"
#include "Character/Projet2Character.h"
#include "IA/AICharacter.h"


UAnimInstance1::UAnimInstance1()
{
	Speed = 0.0;
	bIsHoldingItem = false;
	MyGameState = GetWorld() != NULL ? GetWorld()->GetGameState<AMyGameState>() : NULL;
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
		bIsHoldingItem = static_cast<AProjet2Character*>(OwningActor)->bIsHoldingItem;
	}
	if(OwningActor->IsA(AAICharacter::StaticClass()))
	{
		bIsHoldingItem = static_cast<AAICharacter*>(OwningActor)->bHolding;
	}
	if (MyGameState != NULL)
	{
		bIsWin = MyGameState->bIsWin;
		bIsLose = MyGameState->bIsLose;
	}
	
	
}


