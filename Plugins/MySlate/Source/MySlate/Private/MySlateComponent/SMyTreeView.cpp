#include "SMyTreeView.h"

void SMyTreeView::Construct(const FArguments &InArgs)
{
    FArguments Arguments = InArgs;

    TSharedPtr<UTreeItemData> Test01 =MakeShareable(new UTreeItemData());
    Test01->Name = TEXT("Test01");
    Test01->Height = 100.0f;
    TSharedPtr<UTreeItemData> Test011 =MakeShareable(new UTreeItemData());
    Test011->Name = TEXT("Test011");
    Test011->Height = 50.0f;
    TSharedPtr<UTreeItemData> Test012 = MakeShareable(new UTreeItemData());
    Test012->Name = TEXT("Test012");
    Test012->Height = 50.0f;
    TSharedPtr<UTreeItemData> Test013 =MakeShareable(new UTreeItemData());
    Test013->Name = TEXT("Test013");
    Test013->Height = 50.0f;
    Test01->Children.Add(Test011);
    Test01->Children.Add(Test012);
    Test01->Children.Add(Test013);

    TSharedPtr<UTreeItemData> Test02 = MakeShareable(new UTreeItemData());
    Test02->Name = TEXT("Test02");
    Test02->Height = 100.0f;
    TSharedPtr<UTreeItemData> Test021 = MakeShareable(new UTreeItemData());
    Test021->Name = TEXT("Test021");
    Test021->Height = 50.0f;
    TSharedPtr<UTreeItemData> Test022 = MakeShareable(new UTreeItemData());
    Test022->Name = TEXT("Test022");
    Test022->Height = 50.0f;
    Test02->Children.Add(Test021);
    Test02->Children.Add(Test022);

    TreeItemsSource.Add(Test01);
    TreeItemsSource.Add(Test02);
    Arguments.TreeItemsSource(&TreeItemsSource);
    Arguments.OnGenerateRow_Raw(this, &SMyTreeView::OnGenerateRow);
    Arguments.OnGetChildren_Raw(this, &SMyTreeView::OnGetChildren);

    STreeView::Construct(Arguments);
}

TSharedRef<ITableRow> SMyTreeView::OnGenerateRow(TSharedPtr<UTreeItemData> Item, const TSharedRef<STableViewBase> &OwnerTable)
{
    if(Item!=nullptr)
    {
        return SNew(STableRow<TSharedPtr<UTreeItemData>>, OwnerTable)
            [
                SNew(SHorizontalBox)

                +SHorizontalBox::Slot()
                [
                    SNew(STextBlock)
                    .Text(FText::FromString(Item->Name))
                ]

                +SHorizontalBox::Slot()
                .HAlign(HAlign_Right)
                [
                    SNew(STextBlock)
                    .Text(FText::FromString(FString::FromInt(Item->Height)))
                ]
                
            ];
    }
    else
    {
        return SNew(STableRow<TSharedPtr<UTreeItemData>>, OwnerTable)
            [
                SNew(STextBlock)
                .Text(FText::FromString(TEXT("Invalid Item")))
            ];
    }
}

void SMyTreeView::OnGetChildren(TSharedPtr<UTreeItemData> Item, TArray<TSharedPtr<UTreeItemData>> &OutChildren)
{
    if(Item!=nullptr)
    {
        OutChildren = Item->Children;
    }
    else
    {
        OutChildren.Empty();
    }
}
