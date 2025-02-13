#pragma once
#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"

class FCustomAssetEditor;
class FCustomAssetSearchSummoner : public FWorkflowTabFactory
{
public:
    FCustomAssetSearchSummoner(TSharedRef<FCustomAssetEditor> InCustomAssetEditor);

    virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
public:
    inline static const FName TabID = TEXT("CustomAssetSearch");
private:
    TWeakPtr<FCustomAssetEditor> CustomAssetEditor;
};