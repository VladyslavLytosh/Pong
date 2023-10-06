// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayActors/PongBall.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

APongBall::APongBall()
{
	PrimaryActorTick.bCanEverTick = true;
	
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	RootComponent = CapsuleComponent;
	
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	BallMesh->SetupAttachment(RootComponent);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
}

void APongBall::BeginPlay()
{
	Super::BeginPlay();
	
}

void APongBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

