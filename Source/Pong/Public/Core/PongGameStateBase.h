// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Kismet/GameplayStatics.h"
#include "PongGameStateBase.generated.h"


UCLASS()
class PONG_API APongGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	void IncrementScore(int32 PlayerNumber);
	
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UPROPERTY(Replicated)
	int32 PlayerOneScore;
	UPROPERTY(Replicated)
	int32 PlayerTwoScore;
};
