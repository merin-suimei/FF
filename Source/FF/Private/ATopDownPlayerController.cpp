// Fill out your copyright notice in the Description page of Project Settings.

#include "ATopDownPlayerController.h"


ATopDownPlayerController::ATopDownPlayerController()
    : APlayerController()
{
    // Show cursor to be used for gameplay
    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;
}

void ATopDownPlayerController::BeginPlay()
{
    Super::BeginPlay();

    // Block camera rotation
    SetIgnoreLookInput(true);

    // Set view to actor with tag "Main Camera"
    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsWithTag(this, FName("Main Camera"), FoundActors);
    if (FoundActors.Num() != 0)
    {
        SetViewTarget(FoundActors[0]);
    }
}
