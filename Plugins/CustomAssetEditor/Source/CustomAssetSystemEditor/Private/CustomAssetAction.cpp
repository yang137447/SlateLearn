#include "CustomAssetAction.h"
#include "CustomDefineAsset.h"

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
    FAssetTypeActions_Base::OpenAssetEditor(InObjects, EditWithinLevelEditor);
}
