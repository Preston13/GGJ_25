// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Wander.h"

void UBTT_Wander::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
}

EBTNodeResult::Type UBTT_Wander::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return EBTNodeResult::Type();
}

UBTT_Wander::UBTT_Wander()
{
	MoveDelegate.BindUFunction(this, "FinishAttackTask");
	bNotifyTick = true;
	bCreateNodeInstance = true;
}

void UBTT_Wander::FinishWanderTask()
{
}
