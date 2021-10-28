// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameMode/Projet2GameMode.h"
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

	float MaxSpeed = 600;
	int MaxNbIA = 3;

	AProjet2GameMode* PGameMode;

	UPROPERTY(EditAnywhere)
	class UClass* AISpawn;

	UPROPERTY(EditAnywhere)
	class UClass* Food;
	
	UFUNCTION()
	void SpawnIA();
    
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
