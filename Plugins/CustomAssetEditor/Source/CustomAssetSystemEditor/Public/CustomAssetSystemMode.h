#pragma once
#include "CoreMinimal.h"
#include "WorkflowOrientedApp/ApplicationMode.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

class FCustomAssetSystemEditorWindow;

class FCustomAssetSystemMode : public FApplicationMode
{
public:
    FCustomAssetSystemMode(TSharedPtr<FCustomAssetSystemEditorWindow> InCustomAssetSystemWindow);

    // 注册选项卡
    virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;

    // 禁用模式前调用
    virtual void PreDeactivateMode() override;

    // 激活模式后调用
    virtual void PostActivateMode() override;

private:
    // 自定义资产编辑窗口
    TWeakPtr<FCustomAssetSystemEditorWindow> CustomAssetSystemWindow;
    //该模式下所有的选项卡
    FWorkflowAllowedTabSet CustomAssetSystemEditorTabSet;
};
