#include "CustomAssetSystemPrimaryTab.h"
#include "CustomAssetSystemEditorWindow.h"

FCustomAssetSystemPrimaryTab::FCustomAssetSystemPrimaryTab(TSharedPtr<FCustomAssetSystemEditorWindow> InCustomAssetSystemWindow)
    :FWorkflowTabFactory(TEXT("CustomAssetSystemEditorWindow"), InCustomAssetSystemWindow)
{
    CustomAssetSystemWindow = InCustomAssetSystemWindow;
    //选项卡基本设置
    TabLabel = FText::FromString(TEXT("主视口"));
    ViewMenuDescription = FText::FromString(TEXT("打开主视口"));
    ViewMenuTooltip = FText::FromString(TEXT("显示主视口"));
}

TSharedRef<SWidget> FCustomAssetSystemPrimaryTab::CreateTabBody(const FWorkflowTabSpawnInfo &Info) const
{
    return SNew(STextBlock).Text(FText::FromString(TEXT("主视口")));
}

FText FCustomAssetSystemPrimaryTab::GetTabToolTipText(const FWorkflowTabSpawnInfo &Info) const
{
    return FWorkflowTabFactory::GetTabToolTipText(Info);
}
