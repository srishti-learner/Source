// Fill out your copyright notice in the Description page of Project Settings.


#include "Project.h"
#include "AICharacter.h"
#include "BotTargetPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "MyAIController.h"
AMyAIController::AMyAIController()
{
	//Initialize BehaviorTreeComponent, BlackboardComponent and the corresponding key

	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));

	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	BlackboardLocationToGoKey = "LocationToGo";
}

void AMyAIController::Possess(APawn* pawn)
{
	Super::Possess(pawn);

	//Get the possessed Character and check if it's my own AI Character
	AAICharacter* AIChar = Cast<AAICharacter>(pawn);

	if (AIChar)
	{
		//If the blackboard is valid initialize the blackboard for the corresponding behavior tree
		if (AIChar->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(AIChar->BehaviorTree->BlackboardAsset));

			//Start the behavior tree which corresponds to the specific character
			BehaviorComp->StartTree(*AIChar->BehaviorTree);
		}

		/*Populate the array of available bot target points
		The following function needs a TArray of AActors, that's why I declared the
		BotTargetPoints as such. When I will need to get an exact point and compare it,
		I will cast it to the corresponding class (ABotTargetPoint)*/
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABotTargetPoint::StaticClass(), BotTargetPoints);

	}
}
void AMyAIController::SetSeenTarget(APawn* pawn)
{
	//Registers the Pawn that the AI has seen in the blackboard
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(BlackboardTargetKey, pawn);

		//BlackboardComp->SetValueAsObject("LocationToGo", Pawn);

	}
}




