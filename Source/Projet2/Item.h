// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PlayerController.h"

#include "Item.generated.h"

UCLASS()
class PROJET2_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
	UPROPERTY(VisibleAnywhere)
	bool bHolding;
	UPROPERTY(VisibleAnywhere)
	bool bGravity;

	UPROPERTY(VisibleAnywhere)
	float FoodValue;
	

protected:

	UPROPERTY(EditAnywhere)
	USphereComponent* Collider;
	
	UPROPERTY(VisibleAnywhere, Category = Mesh)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	FVector TargetPosition;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UFUNCTION()
		void PickItem();

	UPROPERTY(VisibleAnywhere)
	AActor* Player;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
