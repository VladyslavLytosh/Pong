// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "PongPlayerController.generated.h"


UCLASS()
class PONG_API APongPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void InitializePlayerInput(UInputComponent* PlayerInputComponent);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = true))
	UInputAction* MoveAction;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = true))
	UInputMappingContext* DefaultMappingContext;
	
	void Input_Move(const FInputActionValue& InputActionValue);

	UFUNCTION(Server,Unreliable)
	void Move_Server(FVector Delta);

};
