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
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
public:	
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(VisibleAnywhere, Category = Components)
	UStaticMeshComponent* BallMesh;

	UPROPERTY(VisibleAnywhere, Category = Components)
	UCapsuleComponent* CapsuleComponent;
	
	UPROPERTY(VisibleAnywhere, Category = Components)
	UFloatingPawnMovement* FloatingPawnMovement;

	UPROPERTY(Replicated)
	FVector MoveVector;
	
	UPROPERTY(EditAnywhere, Category = Movement)
	float BallSpeed=1500.f;

	UFUNCTION()
	void OnBallHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void MoveBall(float DeltaTime);
	UFUNCTION(Server, Unreliable)
	void MoveBall_Server();
};
