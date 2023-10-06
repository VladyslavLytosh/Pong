// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayActors/PongBall.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h"

APongBall::APongBall()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	RootComponent = CapsuleComponent;
	
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	BallMesh->SetupAttachment(RootComponent);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));

	
	CapsuleComponent->OnComponentHit.AddDynamic(this, &ThisClass::OnBallHit);

}

void APongBall::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		MoveVector = UKismetMathLibrary::RandomUnitVector().GetSafeNormal2D();
	}
}

void APongBall::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APongBall, MoveVector)
}

void APongBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AddActorLocalOffset(MoveVector*BallSpeed*DeltaTime,true);

}

void APongBall::OnBallHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (HasAuthority())
	{
		MoveVector = UKismetMathLibrary::GetReflectionVector(MoveVector, Hit.ImpactNormal);
		GEngine->AddOnScreenDebugMessage(-1,1,FColor::Red,TEXT("Server OnBallHit"));
	}
}

void APongBall::MoveBall(float DeltaTime)
{
}

void APongBall::MoveBall_Server_Implementation()
{
}

