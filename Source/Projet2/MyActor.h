// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

#include "MyActor.generated.h"

UCLASS()
class AMyActor : public AActor
{
	GENERATED_BODY()

	public:	
        // Sets default values for this actor's properties
        AMyActor();

	protected:

		UPROPERTY(VisibleAnywhere, Category = Mesh)
		USceneComponent* SceneComponent;	
		UPROPERTY(VisibleAnywhere, Category = Mesh)
		UStaticMeshComponent* Mesh;

		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:

		UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
		// Called every frame
		virtual void Tick(float DeltaTime) override;

};
