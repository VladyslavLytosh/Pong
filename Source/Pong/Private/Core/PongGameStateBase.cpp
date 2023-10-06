// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/PongGameStateBase.h"

#include "Net/UnrealNetwork.h"

void APongGameStateBase::IncrementScore(int32 PlayerNumber)
{
	if (HasAuthority())
	{
		if (PlayerNumber == 1)
		{
			GEngine->AddOnScreenDebugMessage(-1,1,FColor::Red,TEXT("Player 1 Scores"));
			PlayerOneScore++;
		}
		else if (PlayerNumber == 2)
		{
			GEngine->AddOnScreenDebugMessage(-1,1,FColor::Yellow,TEXT("Player 2 Scores"));
			PlayerTwoScore++;
		}
	}
}

void APongGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(APongGameStateBase, PlayerOneScore)
	DOREPLIFETIME(APongGameStateBase, PlayerTwoScore)
}
