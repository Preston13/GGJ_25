// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTS_Distance.generated.h"

/**
 * 
 */
UCLASS()
class GGJ_25_API UBTS_Distance : public UBTService
{
	GENERATED_BODY()
	
protected:
	virtual void TickNode(
		UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory,
		float DeltaSeconds
	) override;
};
