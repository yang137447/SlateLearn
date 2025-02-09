// Copyright Epic Games, Inc. All Rights Reserved.

#include "CustomAssetSystemEditor.h"
#include "AssetToolsModule.h"
#include "IAssetTools.h"
#include "CustomAssetAction.h"

#define LOCTEXT_NAMESPACE "FCustomAssetSystemEditorModule"

void FCustomAssetSystemEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	IAssetTools& AssetTool = IAssetTools::Get();
	EAssetTypeCategories::Type CustomAssetCategory = AssetTool.RegisterAdvancedAssetCategory(FName(TEXT("CustomAssetCategory")), LOCTEXT("CustomAssetCategory", "Custom Asset Category"));
	TSharedPtr<IAssetTypeActions> AssetTypeAction = MakeShareable(new CustomAssetAction(CustomAssetCategory));
	AssetTool.RegisterAssetTypeActions(AssetTypeAction.ToSharedRef());
}

void FCustomAssetSystemEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCustomAssetSystemEditorModule, CustomAssetSystemEditor)