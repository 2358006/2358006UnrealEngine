// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChairUp.generated.h"

UCLASS()
class GAMEENGINE1_API AChairUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChairUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void FloatingChair(float deltaTime);

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* chairMesh;

	float floatSpeed = 20.0f;  // 부양 속도
	float floatHeight = 1000.0f; // 부양 최대 높이
	float initialHeight;       // 처음 위치 저장
	bool isRising = true;    // 부양 방향 제어
};
