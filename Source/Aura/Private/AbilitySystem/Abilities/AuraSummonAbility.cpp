// Copyright KittenGames


#include "AbilitySystem/Abilities/AuraSummonAbility.h"
#include "Kismet/KismetSystemLibrary.h"

TArray<FVector> UAuraSummonAbility::GetSpawnLocations()
{
	const FVector Forward = GetAvatarActorFromActorInfo()->GetActorForwardVector();
	const FVector Location = GetAvatarActorFromActorInfo()->GetActorLocation();

	const FVector LeftOfSpread = Forward.RotateAngleAxis(-SpawnSpread / 2.0f, FVector::UpVector);
	const FVector RightOfSpread = Forward.RotateAngleAxis(SpawnSpread / 2.0f, FVector::UpVector);

	// Angle between each vectors to spawn minions along
	const float DeltaSpread = SpawnSpread / NumMinions;
	TArray<FVector> SpawnLocations;
	for (int32 i = 0; i < NumMinions; i++)
	{
		const FVector Direction = LeftOfSpread.RotateAngleAxis(DeltaSpread * i, FVector::UpVector);
		FVector ChosenSpawnLocation = Location + Direction * FMath::FRandRange(MinSpawnDistance, MaxSpawnDistance);
		
		FHitResult Hit;
		GetWorld()->LineTraceSingleByChannel(Hit, ChosenSpawnLocation + FVector(0.0f, 0.0f, 400.0f), ChosenSpawnLocation - FVector(0.0f, 0.0f, 400.0f), ECC_Visibility);
		if (Hit.bBlockingHit)
		{
			ChosenSpawnLocation = Hit.ImpactPoint;
		}

		SpawnLocations.Add(ChosenSpawnLocation);
	}

	/* Debug draw
	
	UKismetSystemLibrary::DrawDebugArrow(GetAvatarActorFromActorInfo(), Location, Location + LeftOfSpread * MaxSpawnDistance, 4.0f, FLinearColor::Green, 3.0f);
	UKismetSystemLibrary::DrawDebugArrow(GetAvatarActorFromActorInfo(), Location, Location + RightOfSpread * MaxSpawnDistance, 4.0f, FLinearColor::Red, 3.0f);

	DrawDebugSphere(GetWorld(), Location + RightOfSpread * MinSpawnDistance, 15.0f, 12, FColor::Blue, false, 3.0f);
	DrawDebugSphere(GetWorld(), Location + RightOfSpread * MaxSpawnDistance, 15.0f, 12, FColor::Blue, false, 3.0f);

	DrawDebugSphere(GetWorld(), Location + LeftOfSpread * MinSpawnDistance, 15.0f, 12, FColor::Blue, false, 3.0f);
	DrawDebugSphere(GetWorld(), Location + LeftOfSpread * MaxSpawnDistance, 15.0f, 12, FColor::Blue, false, 3.0f);
	*/

	return SpawnLocations;
}

TSubclassOf<APawn> UAuraSummonAbility::GetRandomMinionClass()
{
	const int32 Selection = FMath::RandRange(0, MinionClasses.Num() - 1);
	return MinionClasses[Selection];
}
