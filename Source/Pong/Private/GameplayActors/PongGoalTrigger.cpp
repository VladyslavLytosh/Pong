// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayActors/PongGoalTrigger.h"

#include "GameplayActors/PongBall.h"

APongGoalTrigger::APongGoalTrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &ThisClass::OnActorOverlaps);
}

void APongGoalTrigger::OnActorOverlaps(AActor* OverlappedActor, AActor* OtherActor)
{
	if (APongBall* PongBall = Cast<APongBall>(OtherActor))
	{
		if (HasAuthority())
		{
			PongBall->Restart();
		}
	}
}
