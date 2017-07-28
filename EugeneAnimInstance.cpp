// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "EugeneAnimInstance.h"


void UEugeneAnimInstance::NativeInitializeAnimation()
{
	//Very Important Line
	Super::NativeInitializeAnimation();

	//Cache the owning pawn for use in Tick
	OwningPawn = TryGetPawnOwner();
}

//Tick
void UEugeneAnimInstance::NativeUpdateAnimation(float DeltaTimeX)
{
	//Very Important Line
	Super::NativeUpdateAnimation(DeltaTimeX);

	//Always Check Pointers
	if (!OwningPawn)
	{
		return;
	}

	//Set whether moving or not
     bisMoving = (OwningPawn->GetVelocity().SizeSquared() > 25);
}

