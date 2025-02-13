#include "CustomAssetEditorMode.h"
#include "CustomAssetEditor.h"
#include "CustomAssetDetailSummoner.h"
#include "CustomAssetSearchSummoner.h"


FCustomAssetEditorMode::FCustomAssetEditorMode(TSharedRef<FCustomAssetEditor> InCustomAssetEditor, const FName &InModeName)
    :FApplicationMode(InModeName) 
{
    CustomAssetEditor = InCustomAssetEditor;

    TabFactories.RegisterFactory(MakeShareable(new FCustomAssetDetailSummoner(InCustomAssetEditor)));
    TabFactories.RegisterFactory(MakeShareable(new FCustomAssetSearchSummoner(InCustomAssetEditor)));

    TabLayout = FTabManager::NewLayout("Standalone_CustomAssetEditorLayout_v1")
    ->AddArea
    (
        FTabManager::NewPrimaryArea() ->SetOrientation(Orient_Vertical)
        // ->Split
        // (
        //     FTabManager::NewStack()
        //     ->SetSizeCoefficient(0.1f)
        //     ->SetHideTabWell(true)
        //     ->AddTab(InCustomAssetEditor->Getid, ETabState::OpenedTab)
        // )
        ->Split
        (
            FTabManager::NewStack()
            ->SetSizeCoefficient(0.7f)
            ->AddTab(FCustomAssetDetailSummoner::TabID, ETabState::OpenedTab)
            ->AddTab(FCustomAssetSearchSummoner::TabID, ETabState::OpenedTab)
        )
    );
}

void FCustomAssetEditorMode::RegisterTabFactories(TSharedPtr<class FTabManager> InTabManager)
{
    CustomAssetEditor.Pin()->PushTabFactories(TabFactories);
    FApplicationMode::RegisterTabFactories(InTabManager);
}

void FCustomAssetEditorMode::PreDeactivateMode()
{
    FApplicationMode::PreDeactivateMode();
}

void FCustomAssetEditorMode::PostActivateMode()
{
    FApplicationMode::PostActivateMode();
}
