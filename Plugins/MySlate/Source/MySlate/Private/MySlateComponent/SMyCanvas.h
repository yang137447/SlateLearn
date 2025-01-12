#pragma once
#include "CoreMinimal.h"
#include "Widgets/SCanvas.h"

class SMyCanvas : public SCanvas
{
public:
    void Construct( const FArguments& InArgs );

private:
    TArray<FThreadSafeSharedStringPtr> OptionsSource;
    int32 SelectedIndex;
};