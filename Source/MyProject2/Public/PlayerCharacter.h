// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "E:\gay\UE_5.1\Engine\Plugins\EnhancedInput\Source\EnhancedInput\Public\InputActionValue.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class MYPROJECT2_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()



public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PawnClientRestart() override;

#pragma region INPUT

	// INPUT ACTIONS //
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions")
		UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions")
		UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions")
		UInputAction* FireAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions")
		UInputAction* JumpAction;


	// INPUT MAPPINGS //
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions|Mapping")
		UInputMappingContext* BaseMappingContext;


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions|Mapping")
		int32 BaseMappingPriority = 0;

	// INPUT FUNCTIONS //
	void MoveFunc(const FInputActionValue& Value);
	void LookFunc(const FInputActionValue& Value);
	void FireFunc(const FInputActionValue& Value);
	void StopFireFunc(const FInputActionValue& Value);

#pragma endregion

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
