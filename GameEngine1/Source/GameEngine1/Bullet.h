// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletMovementComponent.h"
#include "Bullet.generated.h"

UCLASS()
class GAMEENGINE1_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
    // 발사체의 메쉬
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComponent;

    // 발사체의 이동 컴포넌트
    UPROPERTY(VisibleAnywhere)
    UBulletMovementComponent* BulletMovement;

    // 발사체 속도 (초기값)
    UPROPERTY(EditAnywhere)
    float Speed = 2000.0f;

    // 발사체 초기화 함수
    void InitializeBullet(const FVector& Direction);

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
