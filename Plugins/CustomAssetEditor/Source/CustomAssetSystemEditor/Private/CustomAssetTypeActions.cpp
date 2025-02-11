#include "CustomAssetTypeActions.h"
#include "CustomDefineAsset.h"

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
    FAssetTypeActions_Base::OpenAssetEditor(InObjects, EditWithinLevelEditor);
}

uint32 FCustomAssetTypeActions::GetCategories()
{
    return AssetCategory;
}
