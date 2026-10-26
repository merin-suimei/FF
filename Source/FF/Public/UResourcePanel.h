#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

#include "AInventoryStorage.h"

#include "UResourcePanel.generated.h"

UCLASS()
class FF_API UResourcePanel : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;
    FDelegateHandle OnInventoryUpdateHandle;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* Resource_A_Text;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* Resource_B_Text;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* Resource_C_Text;

    UFUNCTION()
    void HandleInventoryUpdate();
    AInventoryStorage* Inventory;
};
