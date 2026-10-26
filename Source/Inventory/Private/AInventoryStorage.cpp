#include "AInventoryStorage.h"

AInventoryStorage::AInventoryStorage()
{
    // Initialize all resources to 0
    for (const auto resource : {EResources::Resource_A, EResources::Resource_B, EResources::Resource_C})
    {
        mResourceStorage[resource] = 0;
    }
}

AInventoryStorage::~AInventoryStorage()
{
}

const std::map<EResources, int> AInventoryStorage::GetResources() const
{
    return mResourceStorage;
}

bool AInventoryStorage::AdjustResource(EResources resource, int quantity)
{
    int newAmount = mResourceStorage[resource] + quantity;
    if (newAmount < 0 || newAmount > mMaxAmount)
    {
        return false;
    }

    mResourceStorage[resource] = newAmount;

    OnInventoryUpdate.Broadcast();
    return true;
}

bool AInventoryStorage::TakeResourceList(std::map<EResources, int> resourceList) {
    // Check if all resources are available
    for (const auto resource : resourceList) {
        if (mResourceStorage[resource.first] < resource.second) {
            return false;
        }
    }

    for (const auto resource : resourceList) {
        mResourceStorage[resource.first] -= resource.second;
    }

    OnInventoryUpdate.Broadcast();
    return true;
}
