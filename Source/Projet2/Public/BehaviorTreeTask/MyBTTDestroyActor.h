// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "IA/MyAIController1.h"
#include "Actor/Spawner.h"
#include "MyBTTDestroyActor.generated.h"

/**
 * 
 */
UCLASS()
class PROJET2_API UMyBTTDestroyActor : public UBTTaskNode
{
	GENERATED_BODY()
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
