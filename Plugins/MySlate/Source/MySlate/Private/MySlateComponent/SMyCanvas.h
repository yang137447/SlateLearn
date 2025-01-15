#pragma once
#include "CoreMinimal.h"
#include "Widgets/SCanvas.h"
class SMyGridPanel;

class SMyCanvas : public SCanvas
{
public:
    void Construct(const FArguments &InArgs);

    TSharedRef<ITableRow> OnGenerateTile(TSharedPtr<FString> InItem, const TSharedRef<STableViewBase> &OwnerTable);

private:
    TArray<TSharedPtr<FString>> OptionsSource;
    int32 SelectedIndex;
    TSharedPtr<SMyGridPanel> MyGridPanel;
    // TArray<FThreadSafeSharedStringPtr<FString>> OptionsSource;
};