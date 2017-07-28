// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "MyAIController.generated.h"

/**
 * Controller for AI Bot. Dated 25-07-2017
 */
UCLASS()
class PROJECT_API AMyAIController : public AAIController
{
	   GENERATED_BODY()

		UBehaviorTreeComponent *BehaviorComp;
	    UBlackboardComponent *BlackboardComp;
		/*Blackboard keys*/
		UPROPERTY(EditDefaultsOnly, Category = "AI")
			FName BlackboardLocationToGoKey;

		TArray<AActor*> BotTargetPoints;

		/*Posses is executed when the character we want to control is spawned.
		Inside this function, we initialize the blackboard and start the behavior tree*/
		virtual void Possess(APawn* Pawn) override;
		

public:

	/*----------Constructor----------*/
	AMyAIController();
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName BlackboardTargetKey = "Target";
	/*Sets the sensed target in the blackboard*/
	void SetSeenTarget(APawn * pawn);

	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }

	FORCEINLINE TArray<AActor*> GetAvailableTargetPoints() { return BotTargetPoints; }
};
