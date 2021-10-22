// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projet2/Projet2GameMode.h"
#include "Spawner.generated.h"

UCLASS()
class PROJET2_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

    float TimeBeforeSpawn;

	int NbIA;

	int MaxNbIA = 1;

	AProjet2GameMode* PGameMode;
	
	UFUNCTION()
	void SpawnIA();
    
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
