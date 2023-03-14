// Fill out your copyright notice in the Description page of Project Settings.


#include "MHUD.h"
#include "SMenuSlateWidget.h"
#include "Widgets/SWeakWidget.h"
#include "GameFramework/PlayerController.h"

void AMHUD::BeginPlay()
{
  Super::BeginPlay();
  ShowMenu();
}

void AMHUD::ShowMenu()
{
  
  //引擎的全局指针
  if (GEngine && GEngine->GameViewport) {
    //主菜单的小部件
    MenuWidget = SNew(SMenuSlateWidget).OwningHUD(this);
    //SAssignNew允许将小部件储存在一个变量中
    GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(MenuWidget.ToSharedRef()));
    if (PlayerOwner) {
      PlayerOwner->bShowMouseCursor = true;
      PlayerOwner->SetInputMode(FInputModeUIOnly());
    }
  }
}

void AMHUD::RemoveMenu()
{
  if (GEngine && GEngine->GameViewport&&MenuWidgetContainer.IsValid()) {
     GEngine->GameViewport->RemoveViewportWidgetContent(MenuWidgetContainer.ToSharedRef());
      if (PlayerOwner) {
      PlayerOwner->bShowMouseCursor = false;
      PlayerOwner->SetInputMode(FInputModeUIOnly());
    }
  }
}
