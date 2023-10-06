// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PongHUD.generated.h"


UCLASS()
class PONG_API APongHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = GameHUD, meta = (AllowPrivateAccess = true))
	TSubclassOf<UUserWidget> PlayerHUDClass;

private:
	UPROPERTY()
	UUserWidget* PlayerHUDWidget;
};
