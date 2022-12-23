// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "EnhancedInput/Public/EnhancedInputSubsystems.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		// Get the Enhanced Input Local Player Subsystem from the Local Player related to our Player Controller.
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			// PawnClientRestart can run more than once in an Actor's lifetime, so start by clearing out any leftover mappings.
			Subsystem->ClearAllMappings();

			// Add each mapping context, along with their priority values. Higher values outprioritize lower values.
			Subsystem->AddMappingContext(BaseMappingContext, BaseMappingPriority);
		}
	}

	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		PEI->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::MoveFunc);
		PEI->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::LookFunc);
		PEI->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		PEI->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		PEI->BindAction(FireAction, ETriggerEvent::Started, this, &APlayerCharacter::FireFunc);
		PEI->BindAction(FireAction, ETriggerEvent::Completed, this, &APlayerCharacter::StopFireFunc);
	}

}

// 
void APlayerCharacter::MoveFunc(const FInputActionValue& Value) 
{

	if (Value.GetMagnitude() != 0.0f) {
		// Add X axis movement
		AddMovementInput(this->GetActorRightVector(), Value[0]);
		// ADD Y axis movement
		AddMovementInput(this->GetActorForwardVector(), Value[1]);
	}
}

void APlayerCharacter::LookFunc(const FInputActionValue& Value)
{
	AddControllerPitchInput(Value[1] * -1);
	AddControllerYawInput(Value[0]);
}

void APlayerCharacter::FireFunc(const FInputActionValue& Value)
{

}

void APlayerCharacter::StopFireFunc(const FInputActionValue& Value)
{

}

void APlayerCharacter::PawnClientRestart() {
	
	Super::PawnClientRestart();


}