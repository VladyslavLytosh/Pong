// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayActors/PongBall.h"

#include "Components/CapsuleComponent.h"
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
	
	CapsuleComponent->OnComponentHit.AddDynamic(this, &ThisClass::OnBallHit);
}


void APongBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AddActorLocalOffset(MoveVector * BallSpeed * DeltaTime,true);
}

void APongBall::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APongBall, MoveVector)
}

void APongBall::OnBallHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (HasAuthority())
	{
		MoveVector = UKismetMathLibrary::GetReflectionVector(MoveVector, Hit.ImpactNormal);
	}
}

void APongBall::Restart()
{
	if (HasAuthority())
	{
		SetActorLocation(FVector(0,0,110.f));
		
		MoveVector = UKismetMathLibrary::RandomUnitVector().GetSafeNormal2D();
	}
}

