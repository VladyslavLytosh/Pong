// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/PongGameStateBase.h"

#include "Net/UnrealNetwork.h"

void APongGameStateBase::IncrementScore(int32 PlayerNumber)
{
	if (!(PlayerNumber == 1 || PlayerNumber == 2)) return;
		
	if (HasAuthority())
	{
		if (PlayerNumber == 1)
		{
			PlayerOneScore++;
		}
		else if (PlayerNumber == 2)
		{
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
