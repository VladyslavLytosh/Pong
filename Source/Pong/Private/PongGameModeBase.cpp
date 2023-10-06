// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGameModeBase.h"

#include "GameplayActors/PongBall.h"
#include "Kismet/GameplayStatics.h"

void APongGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	
	if (GetNumPlayers() == MaxPlayersInLobby)
	{
		StartGame();
		OnAllPlayersConnects.Broadcast();
	}
}

void APongGameModeBase::StartGame()
{
	TArray<AActor*> PongBalls;
	UGameplayStatics::GetAllActorsOfClass(this,APongBall::StaticClass(),PongBalls);

	for (const auto& PongBall : PongBalls)
	{
		if (APongBall* GamePongBall = Cast<APongBall>(PongBall))
		{
			GamePongBall->Restart();
		}
	}
}


