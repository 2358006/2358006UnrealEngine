// Fill out your copyright notice in the Description page of Project Settings.


#include "ChairUp.h"

// Sets default values
AChairUp::AChairUp()
{
 	// Set this actor to call Tick() every frame.  You can co improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 의자 컴포넌트 생성
	chairMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("orthopedic_chair"));
RootComponent = chairMesh;
}

// Called when the game starts or when spawned
void AChairUp::BeginPlay()
{
	Super::BeginPlay();

	// 처음 높이(Z축) 저장
	initialHeight = GetActorLocation().Z;
	
}

// Called every frame
void AChairUp::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	// 의자 부양 기능 호출
	FloatingChair(deltaTime);

}

void AChairUp::FloatingChair(float deltaTime)
{
	FVector currentLocation = GetActorLocation();

	// Z좌표 상승 중일때 와 아닐때 처리
	if(isRising)
	{
		currentLocation.Z += floatSpeed * deltaTime;
		if(currentLocation.Z >= initialHeight + floatHeight)
		{
			isRising = false;
		}
	}

	else
	{
		currentLocation.Z -= floatSpeed * deltaTime;
		if(currentLocation.Z <= initialHeight)
		{
			isRising = true;
		}
	}
	SetActorLocation(currentLocation);
}

