// Copyright KittenGames

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AuraGameplayAbility.h"
#include "AuraSummonAbility.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraSummonAbility : public UAuraGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = Summoning)
	int32 NumMinions = 5;

	UPROPERTY(EditDefaultsOnly, Category = Summoning)
	TArray<TSubclassOf<APawn>> MinionClasses;

	UPROPERTY(EditAnywhere, Category = Summoning)
	float MinSpawnDistance = 150.0f;

	UPROPERTY(EditAnywhere, Category = Summoning)
	float MaxSpawnDistance = 400.0f;

	UPROPERTY(EditAnywhere, Category = Summoning)
	float SpawnSpread = 90.0f;

	UFUNCTION(BlueprintCallable)
	TArray<FVector> GetSpawnLocations();

	UFUNCTION(BlueprintPure, Category = Summoning)
	TSubclassOf<APawn> GetRandomMinionClass();
};
