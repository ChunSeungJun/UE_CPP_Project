// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "C_ClickMove.generated.h"

/**
 * 
 */
UCLASS()
class UE_PROJECT_API AC_ClickMove : public APlayerController
{
	GENERATED_BODY()
	
public:
	AC_ClickMove();

protected:
	bool bClickRightMouse;

	void InputRightMouseButtonPressed();

	void InputRightMouseButtonReleased();

	void SetNewDestination(const FVector Destination);

	void MoveToMouseCursor();

	virtual void SetupInputComponent() override;

	virtual void PlayerTick(float Deltatime) override;
};
