// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTDropItem.h"
#include "MyAIController1.h"

EBTNodeResult::Type UMyBTTDropItem::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AMyAIController1* AICon = Cast<AMyAIController1>(OwnerComp.GetAIOwner());

	if(AICon)
	{
		if(AICon->AIChar)
		{
			if(AICon->CurrentPoint != nullptr)
			{
				if((AICon->CurrentPoint)->bHasItem == false)
				{
					if(AICon->AIChar->bHolding)
					{
						AICon->AIChar->Drop();
						AICon->AIChar->CurrentItem->SetActorLocation(AICon->CurrentPoint->GetActorLocation());
						AICon->AIChar->bItemOnTarget = true;
					}
					return EBTNodeResult::Succeeded;
				}
			}
		}
	}
	return EBTNodeResult::Failed;
}
