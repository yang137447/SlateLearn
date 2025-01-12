#include "SMyListView.h"

void SMyListView::Construct(const FArguments &InArgs)
{
    ListItemsSource.Add(MakeShared<FListItemData>(FListItemData{TEXT("Item01")}));
    ListItemsSource.Add(MakeShared<FListItemData>(FListItemData{TEXT("Item02")}));
    ListItemsSource.Add(MakeShared<FListItemData>(FListItemData{TEXT("Item03")}));
    ListItemsSource.Add(MakeShared<FListItemData>(FListItemData{TEXT("Item04")}));

    FArguments Arguments = InArgs;
    Arguments.ListItemsSource(&ListItemsSource);
    Arguments.OnGenerateRow_Raw(this, &SMyListView::OnGenerateRow);

    SListView::Construct(Arguments);
}

TSharedRef<ITableRow> SMyListView::OnGenerateRow(TSharedPtr<FListItemData> Item, const TSharedRef<STableViewBase> &OwnerTable)
{
    if(Item!=nullptr)
    {
        return SNew(STableRow<TSharedPtr<FListItemData>>, OwnerTable)
            [
                SNew(STextBlock)
                .Text(FText::FromString(Item->Name))
            ];
    }
    else
    {
        return SNew(STableRow<TSharedPtr<FListItemData>>, OwnerTable)
            [
                SNew(STextBlock)
                .Text(FText::FromString(TEXT("Invalid Item")))
            ];
    }
}
