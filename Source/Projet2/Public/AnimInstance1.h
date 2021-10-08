// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include "AnimInstance1.generated.h"
/**
 * 
 */
UCLASS(Transient, Blueprintable, HideCategories=AnimInstance, Blueprintable)
class UAnimInstance1: public UAnimInstance
{
	GENERATED_BODY()

public:
	UAnimInstance1();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Generic")
	float Speed;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
/*PROJET2_API AnimInstance1
{
public:
	AnimInstance1();
	~AnimInstance1();
};*/
