#include "CustomAssetSystemMode.h"
#include "CustomAssetSystemEditorWindow.h"
#include "CustomAssetSystemPrimaryTab.h"
#include "CustomAssetSystemPropertiesTab.h"

FCustomAssetSystemMode::FCustomAssetSystemMode(TSharedPtr<FCustomAssetSystemEditorWindow> InCustomAssetSystemWindow)
    : FApplicationMode(TEXT("CustomAssetSystemMode"))
{
    CustomAssetSystemWindow = InCustomAssetSystemWindow;
    TSharedPtr<FCustomAssetSystemPrimaryTab> CustomAssetSystemPrimaryTab = MakeShareable(new FCustomAssetSystemPrimaryTab(InCustomAssetSystemWindow));
    CustomAssetSystemEditorTabSet.RegisterFactory(CustomAssetSystemPrimaryTab);
    TSharedPtr<FCustomAssetSystemPropertiesTab> CustomAssetSystemPropertiesTab = MakeShareable(new FCustomAssetSystemPropertiesTab(InCustomAssetSystemWindow));
    CustomAssetSystemEditorTabSet.RegisterFactory(CustomAssetSystemPropertiesTab);

    // 创建初始化布局
    TabLayout = FTabManager::NewLayout("CustomAssetSystemLayout_V1_3")
        ->AddArea(
            FTabManager::NewPrimaryArea()
                ->SetOrientation(Orient_Vertical)
                ->Split(FTabManager::NewSplitter())
                    ->SetOrientation(Orient_Horizontal)
                    ->Split(
                        FTabManager::NewStack()
                        ->SetSizeCoefficient(0.8f)
                        ->AddTab("CustomAssetSystemPrimaryTab", ETabState::OpenedTab)
                        )
                    ->Split(
                        FTabManager::NewStack()
                        ->SetSizeCoefficient(0.2f)
                        ->AddTab("CustomAssetSystemPropertiesTab", ETabState::OpenedTab)
                        )
                );
}

void FCustomAssetSystemMode::RegisterTabFactories(TSharedPtr<FTabManager> InTabManager)
{
    TSharedPtr<FCustomAssetSystemEditorWindow> _CustomAssetSystemWindow = this->CustomAssetSystemWindow.Pin();
    _CustomAssetSystemWindow->PushTabFactories(CustomAssetSystemEditorTabSet);
    FApplicationMode::RegisterTabFactories(InTabManager);
}

void FCustomAssetSystemMode::PreDeactivateMode()
{
    FApplicationMode::PreDeactivateMode();
}

void FCustomAssetSystemMode::PostActivateMode()
{
    FApplicationMode::PostActivateMode();
}
