// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

#include "AICharacter.h"
#include "Projet2Character.h"



// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetRelativeScale3D(FVector(0.25f,0.25f,0.25f));
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
	int randValue = FMath::RandRange(0,10);
	if(randValue <= 1)
	{
		FoodValue = 2;
		Mesh->SetRelativeScale3D(FVector(0.5f,0.5f,0.5f));
	}else
	{
		FoodValue = 1;
	}
}

void AItem::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor->IsA(AProjet2Character::StaticClass()))
	{
		if(static_cast<AProjet2Character*>(OtherActor)->CurrentItem == nullptr)
		{
			static_cast<AProjet2Character*>(OtherActor)->CurrentItem = this;
		}

	}
}

void AItem::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if(OtherActor->IsA(AProjet2Character::StaticClass()))
	{
		if(static_cast<AProjet2Character*>(OtherActor)->CurrentItem == this){
			static_cast<AProjet2Character*>(OtherActor)->CurrentItem = nullptr;
		}
	}
}

void AItem::PickItem(AActor* Holder)
{
	bHolding = true;
	bGravity = false;
	Mesh->SetEnableGravity(bGravity);
	Mesh->SetSimulatePhysics(false);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	if(Holder->IsA(AProjet2Character::StaticClass()))
	{
		AttachToComponent(static_cast<AProjet2Character*>(Holder)->FP_FistLocation,FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
	if(Holder->IsA(AAICharacter::StaticClass()))
	{
		AttachToComponent(static_cast<AAICharacter*>(Holder)->FP_FistLocation,FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
}

void AItem::DropItem()
{
	bHolding = false;
	bGravity = true;
	Mesh->SetEnableGravity(bGravity);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
}



// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

