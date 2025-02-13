#include "CustomAssetDetailSummoner.h"
#include "EditorStyleSet.h"
#include "CustomAssetEditor.h"
#include "CustomAssetDetailSummoner.h"

#define LOCTEXT_NAMESPACE "CustomAssetDetailSummoner"

FCustomAssetDetailSummoner::FCustomAssetDetailSummoner(TSharedRef<FCustomAssetEditor> InCustomAssetEditor)
    :FWorkflowTabFactory(TabID, InCustomAssetEditor),
    CustomAssetEditor(InCustomAssetEditor)
{
    TabLabel = LOCTEXT("CustomAssetDetailsTabLabel", "Custom Asset Details");
    TabIcon = FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details");

    bIsSingleton = true;

    ViewMenuDescription = LOCTEXT("CustomAssetDetailsViewMenuDesc", "Custom Asset Details");
    ViewMenuTooltip = LOCTEXT("CustomAssetDetailsViewMenuTooltip", "Show custom asset details tab");
}

TSharedRef<SWidget> FCustomAssetDetailSummoner::CreateTabBody(const FWorkflowTabSpawnInfo &Info) const
{
    auto DetailTextBlock= SNew(STextBlock).Text(FText::FromString(TEXT("Custom Asset Details")));
    return DetailTextBlock;
}

#undef LOCTEXT_NAMESPACE