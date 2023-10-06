// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PongHUD.h"

#include "Blueprint/UserWidget.h"
#include "Core/PongGameStateBase.h"
#include "Kismet/GameplayStatics.h"

void APongHUD::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PlayerController = GetOwningPlayerController();

	checkf(PlayerHUDWidgetClass, TEXT("Widgets classes is not setted"))
	
	PlayerHUDWidget = CreateWidget(PlayerController, PlayerHUDWidgetClass);
	PlayerHUDWidget->AddToViewport();
	PlayerHUDWidget->SetVisibility(ESlateVisibility::Collapsed);
	
	WaitingWidget = CreateWidget(PlayerController, WaitingWidgetClass);
	WaitingWidget->AddToViewport();
	WaitingWidget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

	APongGameStateBase* GameStateBase =  Cast<APongGameStateBase>(UGameplayStatics::GetGameState(this));
	GameStateBase->OnAllPlayersConnectedClient.AddDynamic(this,&ThisClass::OnAllPlayersConnectedClient);
	
}

void APongHUD::OnAllPlayersConnectedClient()
{
	PlayerHUDWidget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	WaitingWidget->SetVisibility(ESlateVisibility::Collapsed);
}


