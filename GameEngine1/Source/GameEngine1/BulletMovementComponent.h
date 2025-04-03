// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"
#include "BulletMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEENGINE1_API UBulletMovementComponent : public UMovementComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBulletMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// 이동 속도 (초기 속도 및 최대 속도)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float InitialSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float MaxSpeed;

	// 이 변수를 추가하여 반사 여부를 제어
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool bShouldBounce;

	// 이 변수를 추가하여 중력 영향을 제어
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float BulletGravityScale;

	// Called every frame
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	// 발사체 이동 방향 설정
	void SetVelocity(const FVector& Direction);

	// bRotationFollowsVelocity 사용: 발사체가 이동 방향에 맞게 회전하도록 설정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	bool bRotationFollowsVelocity;
};
