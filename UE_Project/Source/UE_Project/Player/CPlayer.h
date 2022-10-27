// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPlayer.generated.h"

UCLASS()
class UE_PROJECT_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPlayer();
	

private :
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleDefaultsOnly)
		class UCameraComponent* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private :
	void OnMoveForward(float axis);
	void OnMoveRight(float axis);

	void OnHorizontalLook(float axis);
	void OnVerticalLook(float axis);

	void Run();
	void Walk();

};
