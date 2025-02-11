#include "CustomAssetSystemEditorWindow.h"
#include "CustomAssetSystemMode.h"

FName FCustomAssetSystemEditorWindow::GetToolkitFName() const
{
    return FName(TEXT("CustomAssetSystemEditorWindow"));
}

FText FCustomAssetSystemEditorWindow::GetBaseToolkitName() const
{
    return FText::FromString(TEXT("CustomAssetSystemEditorWindow"));
}

FString FCustomAssetSystemEditorWindow::GetWorldCentricTabPrefix() const
{
    return TEXT("CustomAssetSystemEditorWindow");
}

FLinearColor FCustomAssetSystemEditorWindow::GetWorldCentricTabColorScale() const
{
    return FLinearColor::Green;
}

FString FCustomAssetSystemEditorWindow::GetDocumentationLink() const
{
    return TEXT("https://github.com/yourusername/yourrepository");
}

void FCustomAssetSystemEditorWindow::RegisterTabSpawners(const TSharedRef<FTabManager> &InTabManager)
{
    FWorkflowCentricApplication::RegisterTabSpawners(InTabManager);
}

void FCustomAssetSystemEditorWindow::UnregisterTabSpawners(const TSharedRef<FTabManager> &InTabManager)
{
    FWorkflowCentricApplication::UnregisterTabSpawners(InTabManager);
}

void FCustomAssetSystemEditorWindow::OnToolkitHostingStarted(const TSharedRef<IToolkit> &Toolkit)
{
}

void FCustomAssetSystemEditorWindow::OnToolkitHostingFinished(const TSharedRef<IToolkit> &Toolkit)
{
}

void FCustomAssetSystemEditorWindow::InitAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost> &InitToolkitHost, const FName AppIdentifier, const TSharedRef<FTabManager::FLayout> &StandaloneDefaultLayout, const bool bCreateDefaultStandaloneMenu, const bool bCreateDefaultToolbar, const TArray<UObject *> &ObjectsToEdit, const bool bInIsToolbarFocusable, const bool bInUseSmallToolbarIcons, const TOptional<EAssetOpenMethod> &InOpenMethod)
{
    FWorkflowCentricApplication::InitAssetEditor(
        Mode,
        InitToolkitHost,
        AppIdentifier,
        StandaloneDefaultLayout,
        bCreateDefaultStandaloneMenu,
        bCreateDefaultToolbar,
        ObjectsToEdit
    );
    
    // 添加自定义Mode,并设置
    TSharedPtr<FCustomAssetSystemMode> CustomAssetSystemPrimaryTab = MakeShareable(new FCustomAssetSystemMode(SharedThis(this)));
    AddApplicationMode(FName("CustomAssetSystemEditorMode"), CustomAssetSystemPrimaryTab.ToSharedRef());
    SetCurrentMode(FName("CustomAssetSystemEditorMode"));
}
