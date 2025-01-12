#pragma once

#include "Widgets/Views/SListView.h"

struct FListItemData
{
    FString Name;
};

class SMyListView : public SListView<TSharedPtr<FListItemData>>
{
public:
    void Construct(const FArguments &InArgs);

    TSharedRef<ITableRow> OnGenerateRow(TSharedPtr<FListItemData> Item, const TSharedRef<STableViewBase> &OwnerTable);

    TArray<TSharedPtr<FListItemData>> ListItemsSource;
};