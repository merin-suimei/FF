#pragma once

#include <map>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EResources.h"

#include "AInventoryStorage.generated.h"


UCLASS()
class INVENTORY_API AInventoryStorage : public AActor
{
    GENERATED_BODY()

public:
	AInventoryStorage();
	~AInventoryStorage();
    const std::map<EResources, int> GetResources() const;
    bool AdjustResource(EResources resource, int quantity);
    bool TakeResourceList(std::map<EResources, int> resourceList);

protected:
    std::map<EResources, int> mResourceStorage;
    const int mMaxAmount = 99;
};
