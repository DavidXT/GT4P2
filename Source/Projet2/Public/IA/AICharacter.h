// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"
#include "Perception/PawnSensingComponent.h"
#include <Projet2\Public\Actor\Item.h>
#include "Engine/SkeletalMesh.h"
#include "AICharacter.generated.h"

UCLASS()
class PROJET2_API AAICharacter : public ACharacter
{
	GENERATED_BODY()

	UFUNCTION()
void OnSeePlayer(APawn* InPawn);
	
public:
	
	/*The Behavior Tree of the Character*/
	UPROPERTY(EditAnywhere, Category = AI)
	class UBehaviorTree* BehaviorTree;

	/*The Component which is used for the "seeing" sense of the AI*/
	UPROPERTY(VisibleAnywhere, Category = AI)
	class UPawnSensingComponent* PawnSensingComp;

	UPROPERTY(EditAnywhere)
	class UMaterial* Material1;

	UPROPERTY(EditAnywhere)
	class UMaterial* Material2;

	UPROPERTY(EditAnywhere)
	class UMaterial* Material3;

	UPROPERTY(EditAnywhere)
	class USkeletalMesh* MeshFemale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UClass* AnimFemale;

	UPROPERTY(EditAnywhere)
	class USkeletalMesh* MeshMale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UClass* AnimMale;

	UPROPERTY(EditAnywhere)
	USceneComponent* FP_FistLocation;

	UPROPERTY(VisibleAnywhere)
	AItem* CurrentItem;

	UPROPERTY(VisibleAnywhere)
	bool bHolding = false;
	
	// Sets default values for this character's properties
	AAICharacter();

	void Pick();
	void Drop();
	void ReturnItem();
	void RandomPlay();
	
	AActor* Spawn;
	bool bItemOnTarget = false;
	bool bAIVisible = false;
	float LastSeenTime;
	float TimeOut = 3.0f;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
