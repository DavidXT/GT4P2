// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"




// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	RootComponent = Mesh;
	
	Collider = CreateDefaultSubobject<USphereComponent>(FName("Collider"));
	Collider->SetupAttachment(Mesh);
	
	bHolding = false;
	bGravity = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	Collider->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnBeginOverlap);
	Collider->OnComponentEndOverlap.AddDynamic(this, &AItem::OnEndOverlap);
}

void AItem::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor->IsA(AProjet2Character::StaticClass()))
	{
		((AProjet2Character*)OtherActor)->currentItem = this;
	}
}

void AItem::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if(OtherActor->IsA(AProjet2Character::StaticClass()))
	{
		((AProjet2Character*)OtherActor)->currentItem = nullptr;
	}
}

void AItem::PickItem()
{
	bHolding = !bHolding;
	bGravity = !bGravity;
	Mesh->SetEnableGravity(bGravity);
	Mesh->SetSimulatePhysics(bHolding ? false : true);
	Mesh->SetCollisionEnabled(bHolding ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryAndPhysics);
}



// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TargetPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	if(bHolding==true)
	{
		SetActorLocationAndRotation(GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation(),GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorRotation());
	}
	
}

