#pragma once
#include "CoreMinimal.h"
#include "WorkflowOrientedApp/ApplicationMode.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

class FCustomAssetEditor;
class FCustomAssetEditorMode : public FApplicationMode
{

public:
    FCustomAssetEditorMode(TSharedRef<FCustomAssetEditor> InCustomAssetEditor, const FName &InModeName);

    // 注册不同的页签工厂类，每个工厂类对应一个页签
    virtual void RegisterTabFactories(TSharedPtr<class FTabManager> InTabManager) override;
    // 关闭该模式时调用，用于保存状态等功能
    virtual void PreDeactivateMode() override;
    // 激活该模式时调用，用于恢复该模式各种状态
    virtual void PostActivateMode() override;

private:
    TWeakPtr<FCustomAssetEditor> CustomAssetEditor;

    FWorkflowAllowedTabSet TabFactories;
};