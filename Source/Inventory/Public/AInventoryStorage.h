#pragma once

#include <map>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EResources.h"

#include "AInventoryStorage.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnInventoryUpdate);

UCLASS(Blueprintable)
class INVENTORY_API AInventoryStorage : public AActor
{
    GENERATED_BODY()

public:
	AInventoryStorage();
	~AInventoryStorage();
    const std::map<EResources, int> GetResources() const;
    bool AdjustResource(EResources resource, int quantity);
    bool TakeResourceList(std::map<EResources, int> resourceList);

	FOnInventoryUpdate OnInventoryUpdate;

protected:
    std::map<EResources, int> mResourceStorage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", UIMin = "0"))
    int mMaxAmount = 99;
};
