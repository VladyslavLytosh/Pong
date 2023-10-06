// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PongGameModeBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllPlayersConnects);

UCLASS()
class PONG_API APongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	FOnAllPlayersConnects OnAllPlayersConnects;

protected:
	virtual void PostLogin(APlayerController* NewPlayer) override;
	
	void StartGame();
	
private:
	int32 MaxPlayersInLobby=2;
};
