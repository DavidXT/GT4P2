// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeTask/MyBTTDropFollow.h"

// Fill out your copyright notice in the Description page of Project Settings.
#include "Actor/TargetActor.h"
#include "IA/MyAIController1.h"

EBTNodeResult::Type UMyBTTDropFollow::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AMyAIController1* AICon = Cast<AMyAIController1>(OwnerComp.GetAIOwner());

	if(AICon)
	{
		if(AICon->AIChar)
		{
			if(AICon->AIChar->bHolding)
			{
				AICon->AIChar->Drop();
			}
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
