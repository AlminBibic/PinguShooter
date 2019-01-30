// Fill out your copyright notice in the Description page of Project Settings.

#include "CPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/SphereComponent.h"


// Sets default values
ACPlayer::ACPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);

	ProjectileSpawnPoint = CreateDefaultSubobject<USphereComponent>(TEXT("SpawnComp"));

	Fish = 10;

}

// Called when the game starts or when spawned
void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPlayer::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}

// Called every frame
void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayer::MoveForward);
}

