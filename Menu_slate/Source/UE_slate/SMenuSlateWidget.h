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
	/*�����﷨��ֱ�ӷ��ʹ���UI*/
	SLATE_BEGIN_ARGS(SMenuSlateWidget){}
	//����MHUD�����
	SLATE_ARGUMENT(TWeakObjectPtr<class AMHUD>,OwningHUD)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	//���캯��
	void Construct(const FArguments& InArgs);

	//����¼�
	FReply OnPlayClicked()const;
	FReply OnQuitClicked()const;

	//����һ������ָ��
	TWeakObjectPtr<class AMHUD> OwningHUD;
	
	//֧�ּ��̽���
	virtual bool SupportsKeyboardFocus()const override {
		return true;
	};
};
