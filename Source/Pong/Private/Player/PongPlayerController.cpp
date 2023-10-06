// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PongPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void APongPlayerController::InitializePlayerInput(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	
	const ULocalPlayer* LP = Cast<ULocalPlayer>(GetLocalPlayer());
	check(LP);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);
	
	Subsystem->ClearAllMappings();
	
	Subsystem->AddMappingContext(DefaultMappingContext,0);
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
}

void APongPlayerController::Input_Move(const FInputActionValue& InputActionValue)
{
	APawn* PlayerPawn = GetPawn();

	const FVector2D Value = InputActionValue.Get<FVector2D>();

	if (Value.X != 0)
	{
		PlayerPawn->AddMovementInput(PlayerPawn->GetActorRightVector(),Value.X);
		Move_Server(PlayerPawn->GetActorLocation());
	}
}

void APongPlayerController::Move_Server_Implementation(FVector NewLocation)
{
	GetPawn()->SetActorLocation(NewLocation,false);
}
