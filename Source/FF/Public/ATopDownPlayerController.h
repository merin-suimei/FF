// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

#include "ATopDownPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FF_API ATopDownPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
    ATopDownPlayerController();

protected:
    virtual void BeginPlay() override;
};
