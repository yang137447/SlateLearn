#include "CustomAssetFactory.h"
#include "CustomDefineAsset.h"

UCustomAssetFactory::UCustomAssetFactory(const FObjectInitializer &ObjectInitializer)
    :Super(ObjectInitializer)
{
    SupportedClass = UCustomDefineAsset::StaticClass();
}

UObject *UCustomAssetFactory::FactoryCreateNew(UClass *InClass, UObject *InParent, FName InName, EObjectFlags Flags, UObject *Context, FFeedbackContext *Warn, FName CallingContext)
{
    return NewObject<UCustomDefineAsset>(InParent, InName, Flags);
}

bool UCustomAssetFactory::CanCreateNew() const
{
    return true;
}
