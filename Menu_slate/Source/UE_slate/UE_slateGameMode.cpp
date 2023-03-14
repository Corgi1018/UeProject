// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_slateGameMode.h"
#include "UE_slateCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MenuPlayerController.h"
#include "MHUD.h"

//��Ϸģʽ
AUE_slateGameMode::AUE_slateGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	//�����ҿ�����
	PlayerControllerClass = AMenuPlayerController::StaticClass();
	//���HUD��
	HUDClass=AMHUD::StaticClass();
}
