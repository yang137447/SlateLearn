#pragma once
#include "CoreMinimal.h"
#include "Widgets/Views/STreeView.h"

class UTreeItemData
{
public:
    FString Name;
    float Height;

    TArray<TSharedPtr<UTreeItemData>> Children;
};

class SMyTreeView : public STreeView<TSharedPtr<UTreeItemData>>
{
public:
    void Construct(const FArguments &InArgs);

    TSharedRef<ITableRow> OnGenerateRow(TSharedPtr<UTreeItemData> Item, const TSharedRef<STableViewBase> &OwnerTable);

    void OnGetChildren(TSharedPtr<UTreeItemData> Item, TArray<TSharedPtr<UTreeItemData>> &OutChildren);

    TArray<TSharedPtr<UTreeItemData>> TreeItemsSource;
};