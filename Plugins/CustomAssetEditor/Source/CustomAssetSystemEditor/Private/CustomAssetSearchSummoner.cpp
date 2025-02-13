#include "CustomAssetSearchSummoner.h"
#include "EditorStyleSet.h"
#include "CustomAssetEditor.h"
#include "CustomAssetSearchSummoner.h"

#define LOCTEXT_NAMESPACE "CustomAssetSearchSummoner"

FCustomAssetSearchSummoner::FCustomAssetSearchSummoner(TSharedRef<FCustomAssetEditor> InCustomAssetEditor)
    :FWorkflowTabFactory(TabID, InCustomAssetEditor),
    CustomAssetEditor(InCustomAssetEditor)
{
    TabLabel = LOCTEXT("CustomAssetSearchsTabLabel", "Custom Asset Searchs");
    TabIcon = FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Searchs");

    bIsSingleton = true;

    ViewMenuDescription = LOCTEXT("CustomAssetSearchsViewMenuDesc", "Custom Asset Searchs");
    ViewMenuTooltip = LOCTEXT("CustomAssetSearchsViewMenuTooltip", "Show custom asset Searchs tab");
}

TSharedRef<SWidget> FCustomAssetSearchSummoner::CreateTabBody(const FWorkflowTabSpawnInfo &Info) const
{
    auto SearchTextBlock= SNew(STextBlock).Text(FText::FromString(TEXT("Custom Asset Searchs")));
    return SearchTextBlock;
}

#undef LOCTEXT_NAMESPACE