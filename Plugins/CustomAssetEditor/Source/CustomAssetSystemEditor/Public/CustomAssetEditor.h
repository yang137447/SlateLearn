#pragma once
#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowCentricApplication.h"

class UCustomDefineAsset;
class FCustomAssetEditor : public FWorkflowCentricApplication, public FEditorUndoClient, public FNotifyHook
{
public:
    // 获取窗口标识
    virtual FName GetToolkitFName() const override;
    // 获取窗口名称
    virtual FText GetBaseToolkitName() const override;
    // 获取标签前缀
    virtual FString GetWorldCentricTabPrefix() const override;
    // 获取标签颜色
    virtual FLinearColor GetWorldCentricTabColorScale() const override;

    void InitEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost> &InitToolkitHost, TArray<UObject *> InObjects);

    // 菜单拓展
    void ExtendMenu();

    void AddMenuBarExtension(FMenuBarBuilder &Builder) const;
    void AddMenuExtension(FMenuBuilder &Builder);
    // 工具栏拓展
    void ExtendToolbar();

    // 获取编辑对象
    FORCEINLINE TArray<UCustomDefineAsset *> GetCustomDefineAsset() const { return CustomDefineAsset; }

private:
    // 编辑对象
    TArray<UCustomDefineAsset *> CustomDefineAsset;
};