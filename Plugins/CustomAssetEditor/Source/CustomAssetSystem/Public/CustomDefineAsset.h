#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"
#include "CustomDefineAsset.generated.h"


UCLASS(BlueprintType)
class CUSTOMASSETSYSTEM_API UCustomDefineAsset : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AssetName;
};