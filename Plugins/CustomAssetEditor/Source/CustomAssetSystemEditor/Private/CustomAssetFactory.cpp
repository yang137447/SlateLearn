#include "CustomAssetFactory.h"
#include "CustomDefineAsset.h"

UCustomAssetFactory::UCustomAssetFactory(const FObjectInitializer& ObjectInitializer)
    :Super(ObjectInitializer)
{
    SupportedClass = UCustomDefineAsset::StaticClass();
}
UObject *UCustomAssetFactory::FactoryCreateNew(UClass *Class, UObject *InParent, FName Name, EObjectFlags Flags, UObject *Context, FFeedbackContext *Warn)
{
    check(Class->IsChildOf(UCustomDefineAsset::StaticClass()));
    return NewObject<UCustomDefineAsset>(InParent, Class, Name, Flags);
}

bool UCustomAssetFactory::CanCreateNew() const
{
    return true;
}