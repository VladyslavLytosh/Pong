// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayActors/PongGoalTrigger.h"

#include "Core/PongGameStateBase.h"
#include "GameplayActors/PongBall.h"
#include "Kismet/GameplayStatics.h"

APongGoalTrigger::APongGoalTrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &ThisClass::OnActorOverlaps);
}

void APongGoalTrigger::OnActorOverlaps(AActor* OverlappedActor, AActor* OtherActor)
{
	if (APongBall* PongBall = Cast<APongBall>(OtherActor))
	{
		APongGameStateBase* GameState = Cast<APongGameStateBase>(UGameplayStatics::GetGameState(this));
		if (!GameState) return;
		
		GameState->IncrementScore(PlayerNumber);
		PongBall->Restart();
	}
}
