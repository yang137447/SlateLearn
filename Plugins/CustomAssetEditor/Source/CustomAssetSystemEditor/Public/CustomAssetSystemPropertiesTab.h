#pragma once
#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"

class FCustomAssetSystemEditorWindow;

class FCustomAssetSystemPropertiesTab : public FWorkflowTabFactory
{
public:
FCustomAssetSystemPropertiesTab(TSharedPtr<FCustomAssetSystemEditorWindow> InCustomAssetSystemWindow);

    //创建选项卡主体
	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
    //选项卡提示
    virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

private:
    TWeakPtr<FCustomAssetSystemEditorWindow> CustomAssetSystemWindow;
};