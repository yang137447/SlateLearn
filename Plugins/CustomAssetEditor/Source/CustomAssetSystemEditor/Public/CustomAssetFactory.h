#pragma once
#include "CoreMinimal.h"
#include "CustomAssetFactory.generated.h"

UCLASS()
class UCustomAssetFactory : public UFactory
{
    GENERATED_BODY()
public:
    UCustomAssetFactory(const FObjectInitializer& ObjectInitializer);

    virtual UObject *FactoryCreateNew(UClass *InClass, UObject *InParent, FName InName, EObjectFlags Flags, UObject *Context, FFeedbackContext *Warn, FName CallingContext) override;
    
    virtual bool CanCreateNew() const override;
};
