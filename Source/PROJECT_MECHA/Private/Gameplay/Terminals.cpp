// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Terminals.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Character/PMCharacter.h"
#include "PM_GameModeBase.h"
#include "Kismet/GameplayStatics.h"


ATerminals::ATerminals()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	SetRootComponent(SceneComponent);

	LeftHolder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left Holder Mesh"));
	LeftHolder->SetupAttachment(SceneComponent);

	RightHolder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right Holder Mesh"));
	RightHolder->SetupAttachment(SceneComponent);

	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxTrigger->SetupAttachment(SceneComponent);
}

void ATerminals::BeginPlay()
{
	Super::BeginPlay();
	
	BoxTrigger->OnComponentBeginOverlap.AddDynamic(this, &ATerminals::PassedThrough);
}

void ATerminals::PassedThrough(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<APMCharacter>(OtherActor))
	{
		if (APM_GameModeBase* GameMode = Cast<APM_GameModeBase>(UGameplayStatics::GetGameMode(this)))
		{
			if(!bIsFinishLine)
				GameMode->IncrementTime(AddedTime);
			else
				GameMode->WinGame();
		}
	}
}
