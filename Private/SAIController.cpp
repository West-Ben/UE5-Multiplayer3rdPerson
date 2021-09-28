// Fill out your copyright notice in the Description page of Project Settings.


#include "SAIController.h"
#include "Perception/AISense.h"
#include "Kismet/GameplayStatics.h"
#include "EnvironmentQuery/EnvQuery.h"
#include "EnvironmentQuery/EnvQueryManager.h"


ASAIController::ASAIController()
{
	MoveToLocation = FVector::ZeroVector;
	FindCoverPosition = nullptr;
	//GetPawn()->
}

void ASAIController::BeginPlay()
{
	Super::BeginPlay();

	Senses = Cast<UAISense>(GetPawn()->GetComponentByClass(UAISense::StaticClass()));
}


void ASAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	return;
}

void ASAIController::FindCoverLocation(FVector startLocation)
{
	if (!GetPawn()) { return; }

	FEnvQueryRequest coverLocation = FEnvQueryRequest(FindCoverPosition, GetPawn());

	coverLocation.Execute(
		EEnvQueryRunMode::SingleResult,
		this,
		&ASAIController::HandleCoverLocation
	);


}

void ASAIController::HandleCoverLocation(TSharedPtr result)
{
	if (result->IsSuccsessful())
	{
		MoveToLocation = result->GetItemAsLocation(0);
	}
}
