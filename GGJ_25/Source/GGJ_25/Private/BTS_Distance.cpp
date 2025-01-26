// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_Distance.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

void UBTS_Distance::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	FVector CurrentLocation = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
	FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	float Distance = static_cast<float>(FVector::Distance(CurrentLocation, PlayerLocation));

	UE_LOG(LogTemp, Warning, TEXT("Distance: %f"), Distance);

	OwnerComp.GetBlackboardComponent()->SetValueAsFloat(TEXT("Distance"), Distance);
}
