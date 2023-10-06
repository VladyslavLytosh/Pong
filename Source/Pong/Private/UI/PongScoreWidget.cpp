// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PongScoreWidget.h"

#include "Components/TextBlock.h"
#include "Core/PongGameStateBase.h"
#include "Kismet/GameplayStatics.h"


void UPongScoreWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	const APongGameStateBase* GameState = Cast<APongGameStateBase>(UGameplayStatics::GetGameState(this));
	if (!GameState) return;
	
	PlayerOneScore->SetText(FText::AsNumber(GameState->GetPlayerOneScore()));
	PlayerTwoScore->SetText(FText::AsNumber(GameState->GetPlayerTwoScore()));
}


