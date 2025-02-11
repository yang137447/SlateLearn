#pragma once
#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowCentricApplication.h"

class UCustomDefineAsset;

class FCustomAssetSystemEditorWindow:public FWorkflowCentricApplication, public FEditorUndoClient, public FNotifyHook
{
    public:
    //获取窗口标识
    virtual FName GetToolkitFName() const override;
    //获取窗口名称
    virtual FText GetBaseToolkitName() const override;
    //获取标签前缀
    virtual FString GetWorldCentricTabPrefix() const override;
    //获取标签颜色
    virtual FLinearColor GetWorldCentricTabColorScale() const override;
    virtual FString GetDocumentationLink() const override;

    //注册Tab
    virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;

    virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;

    //在窗口托管开始和结束时调用（是否进入后台）
    virtual void OnToolkitHostingStarted(const TSharedRef<IToolkit>& Toolkit) override;
    virtual void OnToolkitHostingFinished(const TSharedRef<IToolkit>& Toolkit) override;

    //初始化编辑器
    void InitAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, const FName AppIdentifier, const TSharedRef<FTabManager::FLayout>& StandaloneDefaultLayout, const bool bCreateDefaultStandaloneMenu, const bool bCreateDefaultToolbar, const TArray<UObject*>& ObjectsToEdit, const bool bInIsToolbarFocusable = false, const bool bInUseSmallToolbarIcons = false, const TOptional<EAssetOpenMethod>& InOpenMethod = TOptional<EAssetOpenMethod>());

    //获取编辑对象
    UCustomDefineAsset* GetCustomDefineAsset() const { return CustomDefineAsset; }
private:
    //编辑对象
    UCustomDefineAsset* CustomDefineAsset;
};