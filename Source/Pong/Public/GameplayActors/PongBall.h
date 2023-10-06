// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PongBall.generated.h"

class UFloatingPawnMovement;
class UCapsuleComponent;

UCLASS()
class PONG_API APongBall : public AActor
{
	GENERATED_BODY()
	
public:	
	APongBall();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(VisibleAnywhere, Category = Components)
	UStaticMeshComponent* BallMesh;

	UPROPERTY(VisibleAnywhere, Category = Components)
	UCapsuleComponent* CapsuleComponent;
	
	UPROPERTY(VisibleAnywhere, Category = Components)
	UFloatingPawnMovement* FloatingPawnMovement;
};
