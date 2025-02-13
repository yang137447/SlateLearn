#pragma once
#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"

class FCustomAssetEditor;
class FCustomAssetDetailSummoner : public FWorkflowTabFactory
{
public:
    FCustomAssetDetailSummoner(TSharedRef<FCustomAssetEditor> InCustomAssetEditor);

    virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
public:
    inline static const FName TabID = TEXT("CustomAssetDetail");
private:
    TWeakPtr<FCustomAssetEditor> CustomAssetEditor;
};