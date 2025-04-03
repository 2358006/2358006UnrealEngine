// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletMovementComponent.h"
#include "GameFramework/Actor.h" // GetOwner 함수 사용을 위해

// Sets default values for this component's properties
UBulletMovementComponent::UBulletMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// 기본 속도 설정
	InitialSpeed = 1000.0f;
	MaxSpeed = 1000.0f;
	bRotationFollowsVelocity = true; // 회전 속도에 맞춰 회전하도록 기본값 설정
}


// Called when the game starts
void UBulletMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UBulletMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 이동 처리: 위치 업데이트
	if (GetOwner())
	{
		FVector NewLocation = GetOwner()->GetActorLocation() + Velocity * DeltaTime;
		GetOwner()->SetActorLocation(NewLocation);

		// bRotationFollowsVelocity가 true일 때 회전 처리
		if (bRotationFollowsVelocity)
		{
			FRotator NewRotation = Velocity.Rotation(); // 속도 방향에 맞춰 회전
			GetOwner()->SetActorRotation(NewRotation); // 회전 적용
		}
	}
}

// 발사체의 이동 방향 설정
void UBulletMovementComponent::SetVelocity(const FVector& Direction)
{
	Velocity = Direction.GetSafeNormal() * InitialSpeed;  // 정규화된 방향으로 속도 설정
}
