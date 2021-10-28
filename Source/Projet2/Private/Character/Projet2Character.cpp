// Copyright Epic Games, Inc. All Rights Reserved.

#include "Projet2Character.h"

#include "AICharacter.h"
#include "MyGameState.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
//#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


//////////////////////////////////////////////////////////////////////////
// AProjet2Character

AProjet2Character::AProjet2Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	//Create socket to getItem
	FP_FistLocation = CreateDefaultSubobject<USceneComponent>(TEXT("FistLocation"));
	FP_FistLocation->SetupAttachment(GetCapsuleComponent());

	MeshPersoFemale = CreateDefaultSubobject<USkeletalMesh>(TEXT("MeshFemale"));
	MeshPersoGoblin = CreateDefaultSubobject<USkeletalMesh>(TEXT("MeshMale"));

	bIsHoldingItem = false;
}

//////////////////////////////////////////////////////////////////////////
// Input

void AProjet2Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Pick", IE_Pressed, this, &AProjet2Character::PickItem);
	PlayerInputComponent->BindAction("Pick", IE_Released, this, &AProjet2Character::DropItem);

	PlayerInputComponent->BindAxis("MoveForward", this, &AProjet2Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AProjet2Character::MoveRight);

	InputComponent->BindAction("ZoomIn", IE_Pressed, this, &AProjet2Character::ZoomIn);
	InputComponent->BindAction("ZoomOut", IE_Pressed, this, &AProjet2Character::ZoomOut);

	InputComponent->BindAction("Pause", IE_Pressed, this, &AProjet2Character::Pause).bExecuteWhenPaused = true; 
	
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	
}

void AProjet2Character::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this,&AProjet2Character::OnBeginOverlap);
	MyGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
}

void AProjet2Character::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor->IsA(AAICharacter::StaticClass()))
	{
		AMyGameState* const MyGameState = GetWorld() != NULL ? GetWorld()->GetGameState<AMyGameState>() : NULL;
		if (MyGameState != NULL) {
			MyGameState->Lose();
		}
	}
}

void AProjet2Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//Function to pick Item with player
void AProjet2Character::PickItem()
{
	if(CurrentItem != nullptr)
	{
		CurrentItem->PickItem(this);
		bIsHoldingItem = true;
	}
}

//Function to drop Item with player
void AProjet2Character::DropItem()
{
	if(CurrentItem != nullptr)
	{
		CurrentItem->DropItem();
		bIsHoldingItem = false;
	}
}

void AProjet2Character::MoveForward(float Value)
{
	if(bIsHoldingItem)
	{
		Value = Value/2;
	}
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AProjet2Character::MoveRight(float Value)
{
	if(bIsHoldingItem)
	{
		Value = Value/2;
	}
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void AProjet2Character::ZoomIn()
{
	if (CameraBoom->TargetArmLength >= ZoomConfig.MinCameraLen)
	{
		CameraBoom->TargetArmLength -= ZoomConfig.ZoomStepLen;
	}
	else
	{
		CameraBoom->TargetArmLength = ZoomConfig.MinCameraLen;
	}
}

void AProjet2Character::ZoomOut()
{
	if (CameraBoom->TargetArmLength <= ZoomConfig.MaxCameraLen)
	{
		CameraBoom->TargetArmLength += ZoomConfig.ZoomStepLen;
	}
	else
	{
		CameraBoom->TargetArmLength = ZoomConfig.MaxCameraLen;
	}
}

void AProjet2Character::Pause()
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	MyGameInstance->ClickResume();
}

void AProjet2Character::TwoPerso()
{
	GetMesh()->SetSkeletalMesh(MeshPersoGoblin);
	GetMesh()->SetAnimInstanceClass(AnimPersoGoblin);
}

void AProjet2Character::ThirdPerso()
{
	GetMesh()->SetSkeletalMesh(MeshPersoFemale);
	GetMesh()->SetAnimInstanceClass(AnimPersoFemale);
}