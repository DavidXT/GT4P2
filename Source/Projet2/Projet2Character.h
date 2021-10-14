// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Item.h"
#include "MyUserWidget.h"
#include "MyGameInstance.h"
#include "Components/SceneComponent.h"
#include "Projet2Character.generated.h"

USTRUCT()
struct FZoomData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, Category = Config)
		float MinCameraLen;

	UPROPERTY(EditDefaultsOnly, Category = Config)
		float MaxCameraLen;

	UPROPERTY(EditDefaultsOnly, Category = Config)
		float ZoomStepLen;
};

UCLASS(config=Game)
class AProjet2Character : public ACharacter
{
	GENERATED_BODY()

	
	
	/** Get Animations */
	UPROPERTY(EditDefaultsOnly, Category = animation)
	UAnimSequence* animPickUp;
	
	UPROPERTY(EditDefaultsOnly, Category = animation)
	UAnimSequence* animWalkCarry;
	
	UPROPERTY(EditDefaultsOnly, Category = animation)
	UAnimSequence* animVictory;
	
	UPROPERTY(EditDefaultsOnly, Category = animation)
	UAnimSequence* animDefeat;
	
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditDefaultsOnly, Category = Config)
	FZoomData ZoomConfig;





public:
	AProjet2Character();

	UPROPERTY (VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* Mesh1E;

	UPROPERTY(EditAnywhere)
	USceneComponent* FP_FistLocation;
	
	UMyGameInstance* MyGameInstance;

	UPROPERTY(VisibleAnywhere)
	class UMyUserWidget* currentWidget;

	UPROPERTY(VisibleAnywhere)
	class AItem* currentItem;

	UPROPERTY(VisibleAnywhere)
	bool bIsHoldingItem;
	
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;
	
protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Pick and Drop Item **/
	UFUNCTION()
	void PickItem();
	UFUNCTION()
	void DropItem();

	UFUNCTION(BlueprintCallable, Category = Camera)
	void ZoomIn();

	UFUNCTION(BlueprintCallable, Category = Camera)
	void ZoomOut();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface
	virtual void BeginPlay() override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	//OnBeginOverlap
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

