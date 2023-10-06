// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PongScoreWidget.generated.h"

class UTextBlock;

UCLASS()
class PONG_API UPongScoreWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
private:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlayerOneScore;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlayerTwoScore;
};
