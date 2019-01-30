// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PPlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class PINGUSHOOTER_API APPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USpringArmComponent* SpringArmComp;

	void MoveForward(float Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnComp")
		USphereComponent* ProjectileSpawnPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Root;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
