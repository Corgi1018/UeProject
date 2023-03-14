// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class UE_SLATE_API SMenuSlateWidget : public SCompoundWidget
{
public:
	/*声明语法，直接访问构建UI*/
	SLATE_BEGIN_ARGS(SMenuSlateWidget){}
	//储存MHUD这个类
	SLATE_ARGUMENT(TWeakObjectPtr<class AMHUD>,OwningHUD)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	//构造函数
	void Construct(const FArguments& InArgs);

	//点击事件
	FReply OnPlayClicked()const;
	FReply OnQuitClicked()const;

	//缓存一个对象指针
	TWeakObjectPtr<class AMHUD> OwningHUD;
	
	//支持键盘焦点
	virtual bool SupportsKeyboardFocus()const override {
		return true;
	};
};
