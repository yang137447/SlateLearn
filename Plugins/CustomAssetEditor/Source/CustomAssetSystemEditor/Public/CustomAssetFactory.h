#pragma once

#include "CoreMinimal.h"
#include "CustomAssetFactory.generated.h"

UCLASS()
class CUSTOMASSETSYSTEMEDITOR_API UCustomAssetFactory : public UFactory
{
    GENERATED_BODY()
public:
    UCustomAssetFactory(const FObjectInitializer& ObjectInitializer);
    virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
    virtual bool CanCreateNew() const override;
};