// Fill out your copyright notice in the Description page of Project Settings.


#include "Cannon.h"
#include "Bullet.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
ACannon::ACannon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACannon::BeginPlay()
{
	Super::BeginPlay();

	// 타이머를 설정하여 일정 시간마다 발사
    GetWorld()->GetTimerManager().SetTimer(FireTimerHandle, this, &ACannon::FireBullet, FireRate, true);
}

// Called every frame
void ACannon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACannon::FireBullet()
{
    if (BulletClass)
    {
        FVector SpawnLocation = GetFireLocation();
        FRotator SpawnRotation = GetFireRotation();

        // 발사체를 생성
        ABullet* Bullet = GetWorld()->SpawnActor<ABullet>(BulletClass, SpawnLocation, SpawnRotation);

        if (Bullet)
        {
            // 발사체 초기화 (속도, 방향 등)
            FVector ForwardDirection = SpawnRotation.Vector(); // 회전 정보를 기반으로 방향 벡터 계산
            Bullet->InitializeBullet(ForwardDirection);
        }
    }
}

FVector ACannon::GetFireLocation() const
{
    return GetActorLocation() + FireOffset;
}

FRotator ACannon::GetFireRotation() const
{
    return GetActorRotation();
}

