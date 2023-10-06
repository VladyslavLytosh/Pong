// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/PongGameStateBase.h"

#include "PongGameModeBase.h"
#include "Net/UnrealNetwork.h"


void APongGameStateBase::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		APongGameModeBase* PongGameModeBase  = Cast<APongGameModeBase>(UGameplayStatics::GetGameMode(this));
		
		PongGameModeBase->OnAllPlayersConnects.AddDynamic(this, &ThisClass::OnAllPlayersConnect);
	}
}

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
	DOREPLIFETIME(APongGameStateBase, bAllPlayersConnected)
}

void APongGameStateBase::OnRep_AllPlayersConnected()
{
	OnAllPlayersConnected_Client.Broadcast();
}

void APongGameStateBase::OnAllPlayersConnect()
{
	bAllPlayersConnected = true;	
}
