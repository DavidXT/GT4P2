// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTDestroyActor.h"



EBTNodeResult::Type UMyBTTDestroyActor::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AMyAIController1* AICon = Cast<AMyAIController1>(OwnerComp.GetAIOwner());

	if(AICon)
	{
		if(AICon->AIChar)
		{
		  static_cast<ASpawner*>(AICon->AIChar->Spawn)->NbIA--;
			AICon->AIChar->Destroy();
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
