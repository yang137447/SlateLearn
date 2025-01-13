// Copyright Epic Games, Inc. All Rights Reserved.

#include "MySlateStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Framework/Application/SlateApplication.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FMySlateStyle::StyleInstance = nullptr;

void FMySlateStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();

		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FMySlateStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FMySlateStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MySlateStyle"));
	return StyleSetName;
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FMySlateStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("MySlateStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("MySlate")->GetBaseDir() / TEXT("Resources"));

	Style->Set("MySlate.OpenPluginWindow", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));

	// Define the rounded corner brush
	Style->Set("MySlate.RoundedBorder", new FSlateRoundedBoxBrush(FLinearColor::FromPow22Color(FColor(0,122,204,255)), 8.0f));
		
	return Style;
}

void FMySlateStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FMySlateStyle::Get()
{
	return *StyleInstance;
}
