// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SAIController.generated.h"

class UAISense;
class UEnvQuery;

/**
 *  Base AI controller for Character Enemies and Player Commanded AI
 */

UCLASS()
class UE5FIRSTTEST_API ASAIController : public AAIController
{
	GENERATED_BODY()

public:
	ASAIController();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UAISense* Senses;

	UFUNCTION(BlueprintCallable, Category = AI)
	void FindCoverLocation(FVector startLocation);

	UFUNCTION(BlueprintCallable, Category = AI)
	void HandleCoverLocation(TSharedPtr result);

	UFUNCTION(BlueprintCallable, Category = AI)
	FVector getMoveToLocation() { return MoveToLocation; }
	//TODO: Find Cover Function

	//TODO: Random Location and rotation, should look natural

	//TODO: Comunicate alerts to nerby team AI or Player if player commands

	//TODO: Handel firing and reloading on empty

	//TODO: taking cover on low health or out of ammo

	//TODO: Formations ones for Enemies and ones for Player commands

	UPROPERTY(EditDefaultsOnly, Category = AI)
	UEnvQuery* FindCoverPosition;

protected:


	FVector MoveToLocation;


};
