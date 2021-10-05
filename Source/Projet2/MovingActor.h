// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetActor.h"
#include "Kismet/GameplayStatics.h"

#include "MovingActor.generated.h"

UCLASS()
class PROJET2_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
	public:	
	// Sets default values for this actor's properties
	AMovingActor();

	UPROPERTY(VisibleAnywhere)
	AActor* MoveToTarget;
	
	UPROPERTY(VisibleAnywhere)
	int NbTarget;
	
	UPROPERTY(EditAnywhere, Category=Camera)
	TArray<AActor*> TargetActors;

	protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	public:
	UFUNCTION()
	void MoveTo(float DeltaTime, AActor* Target);

	UFUNCTION()
	void GetTargetActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
