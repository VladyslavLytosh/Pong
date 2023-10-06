// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "PongGoalTrigger.generated.h"


UCLASS()
class PONG_API APongGoalTrigger : public ATriggerBox
{
	GENERATED_BODY()

public:
	APongGoalTrigger();

private:
	UFUNCTION()
	void OnActorOverlaps(AActor* OverlappedActor, AActor* OtherActor);
};
