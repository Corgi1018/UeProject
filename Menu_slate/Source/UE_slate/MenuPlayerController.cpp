// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"
#include "MHUD.h"

AMenuPlayerController::AMenuPlayerController()
{
}

void AMenuPlayerController::SetupInputComponent()
{
  Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindAction("OpenMenu", IE_Pressed, this, &AMenuPlayerController::OpenMenu);
	}
}

void AMenuPlayerController::OpenMenu()
{
	if (AMHUD* MHUD = Cast<AMHUD>(GetHUD())) {
		MHUD->ShowMenu();
	}
}
