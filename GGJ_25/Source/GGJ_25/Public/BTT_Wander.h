// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Wander.generated.h"

/**
 * 
 */
UCLASS()
class GGJ_25_API UBTT_Wander : public UBTTaskNode
{
	GENERATED_BODY()
	
	FScriptDelegate MoveDelegate;

	bool bIsFinished = false;

protected:
	virtual void TickTask(
		UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory,
		float DeltaSeconds
	) override;

public:
	virtual EBTNodeResult::Type ExecuteTask(
		UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory
	) override;

	UBTT_Wander();

	UFUNCTION()
	void FinishWanderTask();
};
