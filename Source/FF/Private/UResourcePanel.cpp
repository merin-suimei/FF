#include "UResourcePanel.h"

void UResourcePanel::NativeConstruct()
{
    Super::NativeConstruct();

    AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), AInventoryStorage::StaticClass());
    Inventory = Cast<AInventoryStorage>(FoundActor);

    OnInventoryUpdateHandle = Inventory->OnInventoryUpdate.AddUObject(this, &UResourcePanel::HandleInventoryUpdate);
    HandleInventoryUpdate();
}

void UResourcePanel::NativeDestruct()
{
    Super::NativeDestruct();

    Inventory->OnInventoryUpdate.Remove(OnInventoryUpdateHandle);
}

void UResourcePanel::HandleInventoryUpdate() {
    if (Inventory != nullptr) {
        auto resources = Inventory->GetResources();

        Resource_A_Text->SetText(FText::AsNumber(resources[EResources::Resource_A]));
        Resource_B_Text->SetText(FText::AsNumber(resources[EResources::Resource_B]));
        Resource_C_Text->SetText(FText::AsNumber(resources[EResources::Resource_C]));
    }
}
