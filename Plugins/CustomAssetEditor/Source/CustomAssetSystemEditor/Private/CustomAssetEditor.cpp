#include "CustomAssetEditor.h"
#include "CustomAssetEditorMode.h"

FName FCustomAssetEditor::GetToolkitFName() const
{
    return FName(TEXT("CustomAssetEditorToolkit"));
}

FText FCustomAssetEditor::GetBaseToolkitName() const
{
    return FText::FromString(TEXT("CustomAssetEditorBaseToolkit"));
}

FString FCustomAssetEditor::GetWorldCentricTabPrefix() const
{
    return TEXT("CustomAssetEditorWorldCentricTabPrefix");
}

FLinearColor FCustomAssetEditor::GetWorldCentricTabColorScale() const
{
    return FLinearColor::Green;
}

void FCustomAssetEditor::InitEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost> &InitToolkitHost, TArray<UObject *> InObjects)
{
    FWorkflowCentricApplication::InitAssetEditor(
        Mode,
        InitToolkitHost,
        FName(TEXT("CustomAssetEditor")),
        FTabManager::FLayout::NullLayout,
        true,
        true,
        InObjects
    );

    AddApplicationMode(FName("CustomAssetEditorMode"), MakeShareable(new FCustomAssetEditorMode(SharedThis(this),FName("CustomAssetEditorMode"))));
    SetCurrentMode(FName("CustomAssetEditorMode"));
}
