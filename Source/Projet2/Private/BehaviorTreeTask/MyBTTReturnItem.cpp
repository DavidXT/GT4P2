// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeTask/MyBTTReturnItem.h"
#include "IA/MyAIController1.h"

EBTNodeResult::Type UMyBTTReturnItem::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AMyAIController1* AICon = Cast<AMyAIController1>(OwnerComp.GetAIOwner());

	if (AICon)
	{
		if (AICon->AIChar)
		{
			AICon->AIChar->ReturnItem();
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
