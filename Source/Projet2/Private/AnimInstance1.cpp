// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance1.h"


UAnimInstance1::UAnimInstance1()
{
	Speed = 0.0;
}



void UAnimInstance1::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	AActor* OwningActor = GetOwningActor();

	if(!OwningActor)
	{
		Speed = OwningActor->GetVelocity().Size();
	}
	
}


