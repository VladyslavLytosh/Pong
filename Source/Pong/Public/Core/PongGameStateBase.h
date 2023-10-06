// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Kismet/GameplayStatics.h"
#include "PongGameStateBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnScoreChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllPlayersConnected_Client);

UCLASS()
class PONG_API APongGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	
	void IncrementScore(int32 PlayerNumber);
	
	FOnScoreChanged OnScoreChanged;
	FOnAllPlayersConnected_Client OnAllPlayersConnected_Client;
	
	FORCEINLINE int32 GetPlayerOneScore() const { return PlayerOneScore; };
	FORCEINLINE int32 GetPlayerTwoScore() const { return PlayerTwoScore; };
	
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UPROPERTY(Replicated)
	int32 PlayerOneScore;
	UPROPERTY(Replicated)
	int32 PlayerTwoScore;
	
	UPROPERTY(Replicated, ReplicatedUsing=OnRep_AllPlayersConnected)
	bool bAllPlayersConnected=false;
	
	UFUNCTION()
	void OnRep_AllPlayersConnected();
	
	UFUNCTION()
	void OnAllPlayersConnect();
};
