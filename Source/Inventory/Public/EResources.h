#pragma once

#include "CoreMinimal.h"
#include "EResources.generated.h"

UENUM(BlueprintType)
enum class EResources : uint8
{
    Resource_A UMETA(DisplayName = "Resource A"),
    Resource_B UMETA(DisplayName = "Resource B"),
    Resource_C UMETA(DisplayName = "Resource C")
};
