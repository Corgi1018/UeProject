// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MHUD.generated.h"

/**
 * 
 */
UCLASS()
class UE_SLATE_API AMHUD : public AHUD
{
	GENERATED_BODY()
protected:
	//储存对菜单的引用
	TSharedPtr<class SMenuSlateWidget>MenuWidget;
	TSharedPtr<class SWidget>MenuWidgetContainer;

	virtual void BeginPlay()override;

public:
	void ShowMenu();
	void RemoveMenu();
};
