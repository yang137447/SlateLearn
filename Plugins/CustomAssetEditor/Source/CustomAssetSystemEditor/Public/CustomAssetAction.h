#pragma once
#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class CustomAssetAction : public FAssetTypeActions_Base
{
public:
    CustomAssetAction(EAssetTypeCategories::Type AssetTypeCategory);

    virtual FText GetName() const override;
    virtual FColor GetTypeColor() const override;
    virtual uint32 GetCategories() override;
    virtual UClass *GetSupportedClass() const override;

    virtual void OpenAssetEditor(const TArray<UObject *> &InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;

private:
    EAssetTypeCategories::Type AssetTypeCategory;
};
