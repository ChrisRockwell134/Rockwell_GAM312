// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "PlayerChar.generated.h"

UCLASS()
class ROCKWELL_GAM312_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Handles the forward and backward movement input
	UFUNCTION()
		void MoveForward(float axisValue);

	//Handles the right and lef movement input
	UFUNCTION()
		void MoveRight(float axisValue);

	//Triggers when jump input is pressed
	UFUNCTION()
		void StartJump();
	
	//Triggers when jump input is released
	UFUNCTION()
		void StopJump();
	
	
	UFUNCTION()
		void FindObject();
	
	//First person camera component attached to the character
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* PlayerCamComp;
};
