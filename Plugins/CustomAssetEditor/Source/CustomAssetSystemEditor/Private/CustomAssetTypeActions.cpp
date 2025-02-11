#include "CustomAssetTypeActions.h"
#include "CustomDefineAsset.h"
#include "CustomAssetEditor.h"

FCustomAssetTypeActions::FCustomAssetTypeActions(EAssetTypeCategories::Type InAssetCategory)
{
    AssetCategory = InAssetCategory;
}

FText FCustomAssetTypeActions::GetName() const
{
    return FText::FromString(TEXT("CustomAsset"));
}

FColor FCustomAssetTypeActions::GetTypeColor() const
{
    return FColor::Green;
}

UClass *FCustomAssetTypeActions::GetSupportedClass() const
{
    return UCustomDefineAsset::StaticClass();
}

void FCustomAssetTypeActions::OpenAssetEditor(const TArray<UObject *> &InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{   
    //默认编辑窗口
    //FAssetTypeActions_Base::OpenAssetEditor(InObjects, EditWithinLevelEditor);

    //自定义编辑窗口
    EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;
    TArray<UObject*> CustomDefineAssets;
    for (UObject* Object : InObjects)
    {
        if(Object->IsA(UCustomDefineAsset::StaticClass()))
        {
            CustomDefineAssets.Add(Object);
        }
    }
    TSharedRef<FCustomAssetEditor> CustomAssetEditor(new FCustomAssetEditor());
    CustomAssetEditor->InitEditor(Mode, EditWithinLevelEditor, CustomDefineAssets);
}

uint32 FCustomAssetTypeActions::GetCategories()
{
    return AssetCategory;
}
