// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerChar.h"

// Sets default values
APlayerChar::APlayerChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initial setup of camera component
	PlayerCamComp = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Cam"));

	//Attaches camera to the character mesh and head bone
	PlayerCamComp->SetupAttachment(GetMesh(), "head");

	//Share rotation with controller
	PlayerCamComp->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void APlayerChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//Binds "MoveForward" axis input to MoveForward
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerChar::MoveForward);
	//Binds "MoveRight" axis input to MoveRight
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerChar::MoveRight);
	//Binds vertical mouse movement axis input to MoveForward to the controllers pitch
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerChar::AddControllerPitchInput);
	//Binds horizontal mouse movement axis input to MoveForward to the controllers yaw
	PlayerInputComponent->BindAxis("Turn", this, &APlayerChar::AddControllerYawInput);
	//Binds the jump action when input is pressed
	PlayerInputComponent->BindAction("JumpEvent", IE_Pressed, this, &APlayerChar::StartJump);
	//Binds the jump action when input is released
	PlayerInputComponent->BindAction("JumpEvent", IE_Released, this, &APlayerChar::StopJump);
}

void APlayerChar::MoveForward(float axisValue)
{
	//Gets the forward direction from controllers rotation
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	//Adds movement input in that direction
	AddMovementInput(Direction, axisValue);
}

void APlayerChar::MoveRight(float axisValue)
{
	//Gets the right direction from controler roation
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	//Adds movement input in that direction
	AddMovementInput(Direction, axisValue);
}

//Called when the jump input is pressed 
void APlayerChar::StartJump()
{
	bPressedJump = true;
}

//Called when the jump input is released
void APlayerChar::StopJump()
{
	bPressedJump = false;
}

void APlayerChar::FindObject()
{
}

