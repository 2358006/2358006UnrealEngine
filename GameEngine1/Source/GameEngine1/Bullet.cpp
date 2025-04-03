// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/StaticMeshComponent.h"
#include "BulletMovementComponent.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // 발사체의 메쉬 컴포넌트 설정
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = MeshComponent;

    // 발사체 이동 컴포넌트 설정
    BulletMovement = CreateDefaultSubobject<UBulletMovementComponent>(TEXT("BulletMovement"));
    BulletMovement->UpdatedComponent = MeshComponent;

    // 기본 이동 속도 설정
    BulletMovement->InitialSpeed = Speed;
    BulletMovement->MaxSpeed = Speed;
    BulletMovement->bRotationFollowsVelocity = true;  // 발사체가 이동 방향으로 회전하도록 설정

    // 중력 적용 여부 설정
    BulletMovement->bShouldBounce = false;  // 충돌 시 튕기지 않도록 설정
    BulletMovement->BulletGravityScale = 1.0f;  // 중력을 적용하고 싶지 않으면 0.0으로 설정

    // 충돌 설정
    MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    MeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block); // 충돌 처리
    MeshComponent->SetSimulatePhysics(true); // 물리 시뮬레이션 활성화
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABullet::InitializeBullet(const FVector& Direction)
{
    // 발사체가 날아갈 방향을 설정
    if (BulletMovement)
    {
        // 방향을 정규화하고, 속도 설정
        FVector NormalizedDirection = Direction.GetSafeNormal();
        BulletMovement->Velocity = NormalizedDirection * Speed;
    }
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + BulletMovement->Velocity * DeltaTime);

}

