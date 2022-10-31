// Fill out your copyright notice in the Description page of Project Settings.


#include "C_ClickMove.h"
#include <Blueprint/AIBlueprintHelperLibrary.h>

AC_ClickMove::AC_ClickMove()
{
	bShowMouseCursor = true;
}

void AC_ClickMove::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("RightClick", IE_Pressed, this, &AC_ClickMove::InputRightMouseButtonPressed);
	InputComponent->BindAction("RightClick", IE_Released, this, &AC_ClickMove::InputRightMouseButtonReleased);
}

void AC_ClickMove::PlayerTick(float Deltatime)
{
	Super::PlayerTick(Deltatime);

	if (bClickRightMouse)
	{
		MoveToMouseCursor();
	}
}

void AC_ClickMove::InputRightMouseButtonPressed()
{
	bClickRightMouse = true;
}

void AC_ClickMove::InputRightMouseButtonReleased()
{
	bClickRightMouse = false;
}

void AC_ClickMove::SetNewDestination(const FVector Destination)
{
	APawn* const MyPawn = GetPawn();

	if (MyPawn)
	{
		float const Distance = FVector::Dist(Destination, MyPawn->GetActorLocation());
		if (Distance > 120.0f)
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, Destination);
		}
	}
}

void AC_ClickMove::MoveToMouseCursor()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		SetNewDestination(Hit.ImpactPoint);
	}
}