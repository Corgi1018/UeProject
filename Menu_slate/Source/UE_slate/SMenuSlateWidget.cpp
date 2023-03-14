// Fill out your copyright notice in the Description page of Project Settings.


#include "SMenuSlateWidget.h"
#include "SlateOptMacros.h"
#include "MHUD.h"
#include "GameFramework/PlayerController.h"
//���屾�ػ��ռ�
#define LOCTEXT_NAMESPACE "MainMenu"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

/*������ʵ�ʹ���UI�ĵط�*/
void SMenuSlateWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;
	OwningHUD = InArgs._OwningHUD;
	//����С�����Ŀռ�
	const FMargin ContentPadding = FMargin(500.f, 300.f);
	const FMargin ButtonPadding = FMargin(10.f);
	//����Text
	const FText TitleText = LOCTEXT("Title", "Menutext");
	const FText PlayText = LOCTEXT("PlayGame", "Play");
	const FText SettingsText = LOCTEXT("Settings", "Settings");
	const FText QuitText = LOCTEXT("QuitGame", "Quit Game");

	//����ʯ����
	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;

	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	TitleTextStyle.Size = 40.f;

	ChildSlot
	[
		// Populate the widget
		SNew(SOverlay)
		+SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.ColorAndOpacity(FColor::Black)
		]
		+SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(ContentPadding)
		[
			SNew(SVerticalBox)
			//Title text
			+SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Font(TitleTextStyle)
				.Text(TitleText)
			  .Justification(ETextJustify::Center)
			]
		  //Play Button
		  +SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this,&SMenuSlateWidget::OnPlayClicked)
				[
					SNew(STextBlock)
				  .Font(ButtonTextStyle)
				  .Text(PlayText)
			    .Justification(ETextJustify::Center)
				]
			]
			 //Setting Button
		  +SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				[
					SNew(STextBlock)
				  .Font(ButtonTextStyle)
				  .Text(SettingsText)
			    .Justification(ETextJustify::Center)
				]
			]
			 //Quit Button
		  +SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this,&SMenuSlateWidget::OnQuitClicked)
				[
					SNew(STextBlock)
				  .Font(ButtonTextStyle)
				  .Text(QuitText)
			    .Justification(ETextJustify::Center)
				]
			]
		]
	];
	
}
FReply SMenuSlateWidget::OnPlayClicked() const
{
	//��־��Ϣ
	UE_LOG(LogTemp, Warning, TEXT("playtest"));
	if (OwningHUD.IsValid())
	{
		OwningHUD->RemoveMenu();
	}
	return FReply::Handled();
}
FReply SMenuSlateWidget::OnQuitClicked() const
{
	UE_LOG(LogTemp, Warning, TEXT("quittest"));
	if (OwningHUD.IsValid()) {
		if (APlayerController*PC=OwningHUD->PlayerOwner)
		{
			PC->ConsoleCommand("quit");
		}
	}
	return FReply::Handled();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
#undef LOCTEXT_NAMESPACE
