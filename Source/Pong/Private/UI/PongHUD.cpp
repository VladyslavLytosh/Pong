// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PongHUD.h"

#include "Blueprint/UserWidget.h"

void APongHUD::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PlayerController = GetOwningPlayerController();

	checkf(PlayerHUDClass, TEXT("Widgets classes is not setted"))
	
	PlayerHUDWidget = CreateWidget(PlayerController, PlayerHUDClass);
	PlayerHUDWidget->AddToViewport();


}
