// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "BotTargetPoint.h"
#include "MyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTTargetPointSelection.h"

EBTNodeResult::Type UBTTargetPointSelection::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AMyAIController* AICon = Cast<AMyAIController>(OwnerComp.GetAIOwner());
	/*If the Controller is valid:
	1)Get the Blackboard Component and the Current Point of the bot
	2)Search for the next point, which will be different from the Current Point*/
	if (AICon)
	{

		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComp();
		ABotTargetPoint* CurrentPoint = Cast<ABotTargetPoint>(BlackboardComp->GetValueAsObject("LocationToGo"));

		TArray<AActor*> AvailableTargetPoints = AICon->GetAvailableTargetPoints();
		max = AvailableTargetPoints.Num()-1;
		//These variables will contain indices in order to determine the next possible point
		int32 currentIndex,nextIndex;

		//Here, we store the possible next target point
		ABotTargetPoint* NextTargetPoint = nullptr;

		//Find a next point which is different from the current one
		do
		{
			if (CurrentPoint)
			{
				currentIndex = CurrentPoint->position;

				if (currentIndex == max) {
					nextIndex = currentIndex--;
					down = true;

				}
				else if (currentIndex == 0) {
					down = false;
					nextIndex = currentIndex++;
				}
				else{
					if (down)
					{
						nextIndex = currentIndex--;
					}
					else {
						nextIndex = currentIndex++;
					}
				}
				
			}
			else {
				nextIndex = 0;
			}
			NextTargetPoint = Cast<ABotTargetPoint>(AvailableTargetPoints[nextIndex]);

		} while (CurrentPoint == NextTargetPoint);
		//Update the next location in the Blackboard so the bot can move to the next Blackboard value
		BlackboardComp->SetValueAsObject("LocationToGo", AvailableTargetPoints[nextIndex]);
		//At this point, the task has been successfully completed
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
UBTTargetPointSelection::UBTTargetPointSelection()
{
	down = false;

}
/*

//This variable will contain a random index in order to determine the next possible point
int32 RandomIndex;

//Here, we store the possible next target point
ABotTargetPoint* NextTargetPoint = nullptr;

//Find a next point which is different from the current one
do
{
RandomIndex = FMath::RandRange(0, AvailableTargetPoints.Num() - 1);
//Remember that the Array provided by the Controller function contains AActor* objects so we need to cast.
NextTargetPoint = Cast<ABotTargetPoint>(AvailableTargetPoints[RandomIndex]);
} while (CurrentPoint == NextTargetPoint);

//Update the next location in the Blackboard so the bot can move to the next Blackboard value
BlackboardComp->SetValueAsObject("LocationToGo", NextTargetPoint);

//At this point, the task has been successfully completed
return EBTNodeResult::Succeeded;
*/
