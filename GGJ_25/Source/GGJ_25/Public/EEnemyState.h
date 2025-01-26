// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum EEnemyState 
{
    Idle UMETA(DisplayName = "Idle"),
    Chase UMETA(DisplayName = "Chasing"),
    Wander UMETA(DisplayName = "Wandering"),
};
