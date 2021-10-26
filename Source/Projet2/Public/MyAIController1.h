// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Projet2/TargetActor.h"
#include "MyAIController1.generated.h"

/**
 * 
 */
UCLASS()
class PROJET2_API AMyAIController1 : public AAIController
{
	GENERATED_BODY()

	/*Behavior tree comp ref*/
	UBehaviorTreeComponent* BehaviorComp;
	
	/*Blackboard comp ref*/
	UBlackboardComponent* BlackboardComp;
	
	/*Blackboard key*/
	UPROPERTY(EditDefaultsOnly, Category = AI)
	FName LocationToGoKey;

	UPROPERTY(EditDefaultsOnly, Category = AI)
	FName BlackboardKey ;

	UPROPERTY(EditDefaultsOnly, Category = AI)
	FName BlackboardPosition ;

	UPROPERTY(EditDefaultsOnly, Category = AI)
	FName BlackboardSpawn ;
		
	TArray<AActor*> BotTargetPoints;



	/*Executes right when the controller possess a Pawn*/
	virtual void OnPossess(APawn* InPawn) override;
	

	public:
	/*----------Constructor----------*/
	AMyAIController1();

	ATargetActor* CurrentPoint;
	AAICharacter* AIChar;

	int CurrentNbMove = 0;

	int NbMoveMax = 3;
	
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }
 
	FORCEINLINE TArray<AActor*> GetAvailableTargetPoints() { return BotTargetPoints; }

	/*Sets the sensed target in the blackboard*/
	void SetSeenTarget(APawn* InPawn);

	void SetItemPosition(FVector ItemPosition);
	void SetNotSeenTarget();
	void SetSpawn();
};
