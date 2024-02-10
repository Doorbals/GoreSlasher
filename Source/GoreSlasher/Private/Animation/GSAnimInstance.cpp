// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/GSAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UGSAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	APawn* Pawn = TryGetPawnOwner();
	if(Pawn == nullptr)
	{
		return;
	}

	CharacterRef = Cast<ACharacter>(Pawn);
	if(CharacterRef != nullptr)
	{
		CharacterMovementCompRef = CharacterRef->GetCharacterMovement();
	}
}

void UGSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	if(CharacterRef != nullptr)
	{
		FHitResult HitResult;
		FVector TraceStart(CharacterRef->GetActorLocation());
		FVector TraceEnd = TraceStart + FVector(0.0f, 0.0f, -1000.0f);

		GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);
		GroundDistance = HitResult.Distance;
	}
}