// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Item.h"
#include "GameMode/MyGameInstance.h"
#include "DepotZone.generated.h"

UCLASS()
class PROJET2_API ADepotZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADepotZone();

	UMyGameInstance* MyGameInstance;
	
	UPROPERTY(EditAnywhere)
	UBoxComponent* Collider;

	UPROPERTY(VisibleAnywhere)
	float UpdateFoodPercent;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
