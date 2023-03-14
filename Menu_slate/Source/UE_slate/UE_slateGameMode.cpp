// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_slateGameMode.h"
#include "UE_slateCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MenuPlayerController.h"
#include "MHUD.h"

//游戏模式
AUE_slateGameMode::AUE_slateGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	//添加玩家控制类
	PlayerControllerClass = AMenuPlayerController::StaticClass();
	//添加HUD类
	HUDClass=AMHUD::StaticClass();
}
