// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Project.h"
#include "ProjectGameMode.h"
#include "ProjectHUD.h"
#include "ProjectCharacter.h"

AProjectGameMode::AProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProjectHUD::StaticClass();
}
