#include "SMyCanvas.h"
#include "SMyTreeView.h"
#include "SMyListView.h"

void SMyCanvas::Construct( const FArguments& InArgs )
{
    SCanvas::Construct(InArgs);

    //添加按钮
    AddSlot()
    .Position(FVector2D(100, 100))
    .Size(FVector2D(100, 40))
    [
        SNew(SButton)
        .HAlign(HAlign_Center)
        .VAlign(VAlign_Center)
        .Text(FText::FromString("Button01"))
    ];

    AddSlot()
    .Position(FVector2D(200, 100))
    .Size(FVector2D(100, 40))
    [
        SNew(SButton)
        .HAlign(HAlign_Center)
        .VAlign(VAlign_Center)
        .Text(FText::FromString("Button02"))
    ];

    //添加选择框
    OptionsSource.Add(MakeShared<FString>("Option01"));
    OptionsSource.Add(MakeShared<FString>("Option02"));
    OptionsSource.Add(MakeShared<FString>("Option03"));
    SelectedIndex = 0;

    AddSlot()
    .Position(FVector2D(300, 100))
    .Size(FVector2D(100, 40))
    [
        SNew(SComboBox<FThreadSafeSharedStringPtr>)
        .OptionsSource(&OptionsSource)
        .OnGenerateWidget_Lambda([](FThreadSafeSharedStringPtr InItem)
        {
            return SNew(STextBlock).Text(FText::FromString(*InItem));
        })
        .OnSelectionChanged_Lambda([this](FThreadSafeSharedStringPtr InItem, ESelectInfo::Type SelectInfo)
        {
            SelectedIndex = OptionsSource.Find(InItem);
        })
        .Content()
        [
            SNew(STextBlock)
            .Text_Lambda([this]()
            {
                if (OptionsSource.IsValidIndex(SelectedIndex))
                {
                    return FText::FromString(*OptionsSource[SelectedIndex]);
                }
                return FText::FromString(TEXT("Invalid Selection"));
            })
        ]
    ];

    //添加水平和垂直盒子
    AddSlot()
    .Position(FVector2D(100, 140))
    .Size(FVector2D(400, 40))
    [
        SNew(SHorizontalBox)

        + SHorizontalBox::Slot()
        .FillWidth(2)
        [
            SNew(SButton)
        ]

        + SHorizontalBox::Slot()
        [
            SNew(SButton)
        ]

        + SHorizontalBox::Slot()
        [
            SNew(SButton)
        ]
    ];

    AddSlot()
    .Position(FVector2D(100, 200))
    .Size(FVector2D(40,100))
    [
        SNew(SVerticalBox)

        + SVerticalBox::Slot()
        .FillHeight(2)
        [
            SNew(SButton)
        ]

        + SVerticalBox::Slot()
        [
            SNew(SButton)
        ]

        + SVerticalBox::Slot()
        [
            SNew(SButton)
        ]
    ];

    //添加树状显示
    AddSlot()
    .Position(FVector2D(500, 100))
    .Size(FVector2D(200,150))
    [
        SNew(SMyTreeView)
    ];

    //添加列表视图
    AddSlot()
    .Position(FVector2D(500, 300))
    .Size(FVector2D(200,150))
    [
        SNew(SMyListView)
    ];

    //添加图片
    AddSlot()
    .Position(FVector2D(100, 200))
    .Size(FVector2D(100, 100))
    [
        SNew(SImage)
        .Image(FCoreStyle::Get().GetBrush("TrashCan"))
    ];

    //添加网格布局
    AddSlot()
    .Position(FVector2D(200, 200))
    .Size(FVector2D(200, 200))
    [
        SNew(SGridPanel)
        .FillRow(0, 1.0f)
        .FillRow(1, 1.0f)
        .FillColumn(0, 1.0f)
        .FillColumn(1, 1.0f)
        + SGridPanel::Slot(0, 0)
        [
            SNew(SImage)
            .Image(FCoreStyle::Get().GetBrush("TrashCan"))
        ]
        + SGridPanel::Slot(1, 0)
        [
            SNew(SImage)
            .Image(FCoreStyle::Get().GetBrush("TrashCan"))
        ]
        + SGridPanel::Slot(0, 1)
        [
            SNew(SImage)
            .Image(FCoreStyle::Get().GetBrush("TrashCan"))
        ]
        + SGridPanel::Slot(1, 1)
        [
            SNew(SImage)
            .Image(FCoreStyle::Get().GetBrush("TrashCan"))
        ]
    ];

}
