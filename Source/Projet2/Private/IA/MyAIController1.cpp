// Fill out your copyright notice in the Description page of Project Settings.


#include <Projet2\Public\IA\MyAIController1.h>
#include "Kismet/GameplayStatics.h"
#include <Projet2\Public\Actor\TargetActor.h>


AMyAIController1::AMyAIController1()
{
	//Initialize BehaviorTreeComponent, BlackboardComponent and the corresponding key
 
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
 
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
 
	LocationToGoKey = "LocationToGo";
	BlackboardKey = "Target";
	BlackboardPosition = "ItemPosition";
	BlackboardSpawn = "bReturnSpawn";
	BlackboardReturnPick = "bPickItem";
	BlackboardCanPick = "bCanPick";
}
 
void AMyAIController1::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
 
	//Get the possessed Character and check if it's my own AI Character
	 AIChar = Cast<AAICharacter>(InPawn);
 
	if (AIChar)
	{
		//If the blackboard is valid initialize the blackboard for the corresponding behavior tree
		if (AIChar->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(AIChar->BehaviorTree->BlackboardAsset));
		}
 
		/*Populate the array of available bot target points
		The following function needs a TArray of AActors, that's why I declared the
		BotTargetPoints as such. When I will need to get an exact point and compare it,
		I will cast it to the corresponding class (ABotTargetPoint)*/
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetActor::StaticClass(), BotTargetPoints);
 
		//Start the behavior tree which corresponds to the specific character
		BehaviorComp->StartTree(*AIChar->BehaviorTree);
	}
}

void AMyAIController1::SetSeenTarget(APawn* InPawn)
{
	//Registers the Pawn that the AI has seen in the blackboard
	if (BlackboardComp)
	{
		AIChar->bAIVisible = true;
		BlackboardComp->SetValueAsVector(BlackboardKey, InPawn->GetActorLocation());
	}
}

void AMyAIController1::SetItemPosition(FVector ItemPosition)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsVector(BlackboardPosition, ItemPosition);
	}
}

void AMyAIController1::SetNotSeenTarget()
{
	if(BehaviorComp)
	{
		AIChar->bAIVisible = false;
		BlackboardComp->ClearValue("Target");
		
		if (AIChar->bItemOnTarget == false)
		{
			BlackboardComp->SetValueAsBool("bPickItem", true);
		}
	}
}

void AMyAIController1::SetSpawn()
{
	if(BehaviorComp)
	{
		BlackboardComp->SetValueAsBool(BlackboardSpawn, true );
	}
}

