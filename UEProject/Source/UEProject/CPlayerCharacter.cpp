// Fill out your copyright notice in the Description page of Project Settings.


#include "CPlayerCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACPlayerCharacter::ACPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	CameraComponent->SetupAttachment((USceneComponent*)GetCapsuleComponent());
	CameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 20.0f + BaseEyeHeight));
	CameraComponent->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ACPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &ACPlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &ACPlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MouseX", this, &ACPlayerCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("MouseY", this, &ACPlayerCharacter::AddControllerPitchInput);

}

void ACPlayerCharacter::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void ACPlayerCharacter::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void ACPlayerCharacter::StartJump()
{
	bPressedJump = true;
}

void ACPlayerCharacter::StopJump()
{
	bPressedJump = false;
}