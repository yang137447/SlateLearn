#include "CustomAssetSystemPropertiesTab.h"
#include "CustomAssetSystemEditorWindow.h"

FCustomAssetSystemPropertiesTab::FCustomAssetSystemPropertiesTab(TSharedPtr<FCustomAssetSystemEditorWindow> InCustomAssetSystemWindow)
    :FWorkflowTabFactory(TEXT("CustomAssetPropertiesTab"), InCustomAssetSystemWindow)
{
    CustomAssetSystemWindow = InCustomAssetSystemWindow;
    //选项卡基本设置
    TabLabel = FText::FromString(TEXT("属性窗口"));
    ViewMenuDescription = FText::FromString(TEXT("打开属性窗口"));
    ViewMenuTooltip = FText::FromString(TEXT("显示属性窗口"));
}

TSharedRef<SWidget> FCustomAssetSystemPropertiesTab::CreateTabBody(const FWorkflowTabSpawnInfo &Info) const
{
    return SNew(STextBlock).Text(FText::FromString(TEXT("属性窗口")));
}

FText FCustomAssetSystemPropertiesTab::GetTabToolTipText(const FWorkflowTabSpawnInfo &Info) const
{
    return FText::FromString(TEXT("属性窗口"));
}
