// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/TargetPoint.h"
#include "BotTargetPoint.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API ABotTargetPoint : public ATargetPoint
{
	GENERATED_BODY()
    public:
		UPROPERTY(EditAnywhere,Category="Values")
		int32 position;
	
	
};
