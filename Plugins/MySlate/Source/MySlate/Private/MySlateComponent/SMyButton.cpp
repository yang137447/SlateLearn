#include "SMyButton.h"

void SMyButton::Construct(const FArguments &InArgs)
{
    SButton::Construct(InArgs);

    this->SetOnClicked(FOnClicked::CreateRaw(this, &SMyButton::OnButtonClicked));
}

FReply SMyButton::OnButtonClicked()
{
    FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Button Clicked!"));
    return FReply::Handled();
}
