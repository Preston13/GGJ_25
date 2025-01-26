// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Chase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "Navigation/PathFollowingComponent.h"
#include "EEnemyState.h"

void UBTT_Chase::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AAIController* AIRef = OwnerComp.GetAIOwner();

	float Distance = OwnerComp.GetBlackboardComponent()->GetValueAsFloat(TEXT("Distance"));
	if (Distance > LostRadius)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsEnum(TEXT("EnemyState"), EEnemyState::Wander);
		AbortTask(OwnerComp, NodeMemory);
		AIRef->StopMovement();
		AIRef->ClearFocus(EAIFocusPriority::Gameplay);
		AIRef->ReceiveMoveCompleted.Remove(MoveDelegate);
		FinishLatentTask(OwnerComp, EBTNodeResult::Aborted);
	}

	if (bIsFinished)
	{
		OwnerComp.GetAIOwner()->ReceiveMoveCompleted.Remove(MoveDelegate);
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}

EBTNodeResult::Type UBTT_Chase::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	bIsAttacking = false;
	bIsFinished = false;
	float Distance = OwnerComp.GetBlackboardComponent()->GetValueAsFloat(TEXT("Distance"));

	AAIController* AIRef = OwnerComp.GetAIOwner();

	if (Distance > AcceptableRadius)
	{
	APawn* PlayerRef = GetWorld()->GetFirstPlayerController()->GetPawn();
	FAIMoveRequest MoveRequest = PlayerRef;
	MoveRequest.SetUsePathfinding(true);
	MoveRequest.SetAcceptanceRadius(AcceptableRadius);

	AIRef->MoveTo(MoveRequest);
	AIRef->SetFocus(PlayerRef);

	AIRef->ReceiveMoveCompleted.AddUnique(MoveDelegate);
	}
	else
	{
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::InProgress;
}

UBTT_Chase::UBTT_Chase()
{
	MoveDelegate.BindUFunction(this, "FinishAttackTask");
	bNotifyTick = true;
	bCreateNodeInstance = true;
}

void UBTT_Chase::FinishAttackTask()
{
	bIsFinished = true;
}