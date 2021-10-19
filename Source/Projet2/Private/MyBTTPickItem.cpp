// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTPickItem.h"
#include "MyAIController1.h"

EBTNodeResult::Type UMyBTTPickItem::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AMyAIController1* AICon = Cast<AMyAIController1>(OwnerComp.GetAIOwner());

	if(AICon)
	{
		if(AICon->AIChar)
		{
			AICon->AIChar->Pick();
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}