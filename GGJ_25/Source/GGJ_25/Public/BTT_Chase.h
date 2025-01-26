// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Chase.generated.h"

/**
 * 
 */
UCLASS()
class GGJ_25_API UBTT_Chase : public UBTTaskNode
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float AcceptableRadius = 300.0f;

	UPROPERTY(EditAnywhere)
	float LostRadius = 1000.0f;

	UPROPERTY(EditAnywhere)
	float ChaseSpeed = 400.0f;

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

	UBTT_Chase();

	UFUNCTION()
	void FinishAttackTask();

};
