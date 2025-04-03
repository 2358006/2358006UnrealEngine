// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cannon.generated.h"

UCLASS()
class GAMEENGINE1_API ACannon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACannon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    // 발사체의 클래스
    UPROPERTY(EditAnywhere, Category = "Cannon")
    TSubclassOf<class ABullet> BulletClass;

    // 발사 주기 (초)
    UPROPERTY(EditAnywhere, Category = "Cannon")
    float FireRate = 2.0f;

    // 발사 위치
    UPROPERTY(EditAnywhere, Category = "Cannon")
    FVector FireOffset;

    // 타이머 핸들
    FTimerHandle FireTimerHandle;

    // 발사 함수
    void FireBullet();

    // 발사 시 대포의 위치와 방향
    FVector GetFireLocation() const;
    FRotator GetFireRotation() const;
};
