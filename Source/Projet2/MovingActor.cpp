// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingActor.h"

// Sets default values
AMovingActor::AMovingActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	GetTargetActor();
	int randInt = FMath::RandRange(0,NbTarget-1);
	MoveToTarget = TargetActors[randInt];
}

void AMovingActor::MoveTo(float DeltaTime, AActor* Target)
{
	FVector dirPlayer = Target->GetActorLocation();
	FVector dirEnemy = GetActorLocation();
	FVector Direction = dirPlayer - dirEnemy;
	Direction.Normalize();
	float radian = atan2(Direction.Y, Direction.X);
	float degree = radian * 180.f / PI - 90;
	SetActorRotation(FRotator(0,degree,0));
	FVector VMove = FVector(Direction.X, Direction.Y, 0.0f);
	SetActorLocation(dirEnemy + VMove * DeltaTime * 400,true);
	if(	GetDistanceTo(Target) <= 100)
	{
		int randInt = FMath::RandRange(0,NbTarget-1);
		MoveToTarget = TargetActors[randInt];
	}
}

void AMovingActor::GetTargetActor()
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetActor::StaticClass(), TargetActors);
	NbTarget = TargetActors.Num();
}

// Called every frame
void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveTo(DeltaTime,MoveToTarget);
}

