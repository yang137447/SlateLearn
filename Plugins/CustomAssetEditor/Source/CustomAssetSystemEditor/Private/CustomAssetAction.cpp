#include "CustomAssetAction.h"
#include "CustomDefineAsset.h"
#include "CustomAssetSystemEditorWindow.h"

CustomAssetAction::CustomAssetAction(EAssetTypeCategories::Type AssetTypeCategory)
{
    this->AssetTypeCategory = AssetTypeCategory;
}

FText CustomAssetAction::GetName() const
{
    return FText::FromString(TEXT("CustomAsset"));
}

FColor CustomAssetAction::GetTypeColor() const
{
    return FColor::Green;
}

uint32 CustomAssetAction::GetCategories()
{
    return AssetTypeCategory;
}

UClass *CustomAssetAction::GetSupportedClass() const
{
    return UCustomDefineAsset::StaticClass();
}

void CustomAssetAction::OpenAssetEditor(const TArray<UObject *> &InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
    //FAssetTypeActions_Base::OpenAssetEditor(InObjects, EditWithinLevelEditor);

    EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

    TSharedPtr<FCustomAssetSystemEditorWindow> NewCustomDefineAssetEditor(new FCustomAssetSystemEditorWindow());
    if(NewCustomDefineAssetEditor.IsValid())
    {
        NewCustomDefineAssetEditor->InitAssetEditor(
            Mode,
            EditWithinLevelEditor,
            FName(TEXT("CustomAssetSystemEditorWindow")),
            FTabManager::FLayout::NullLayout,
            true,
            true,
            InObjects
            );
    }
}
