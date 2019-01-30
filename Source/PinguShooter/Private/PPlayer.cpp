// Fill out your copyright notice in the Description page of Project Settings.

#include "PPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
APPlayer::APPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = Root;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);

	ProjectileSpawnPoint = CreateDefaultSubobject<USphereComponent>(TEXT("SpawnComp"));
}

// Called when the game starts or when spawned
void APPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void APPlayer::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}

// Called every frame
void APPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APPlayer::MoveForward);

}

