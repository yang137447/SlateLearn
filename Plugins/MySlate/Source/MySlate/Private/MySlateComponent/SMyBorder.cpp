#include "SMyBorder.h"

void SMyBorder::Construct(const FArguments &InArgs)
{
    FArguments Arguments = InArgs;
    Arguments.BorderBackgroundColor(FSlateColor(FLinearColor::FromSRGBColor(FColor(128,195,66,255))));
    Arguments.BorderImage(FCoreStyle::Get().GetBrush("ToolPanel.GroupBorder"));

    SBorder::Construct(Arguments);
}
