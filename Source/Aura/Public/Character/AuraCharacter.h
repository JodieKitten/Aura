// Copyright KittenGames

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();

	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;

protected:


private:
	UPROPERTY(EditAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, Category = Camera)
	UCameraComponent* Camera;

	void InitAbilityActorInfo();

};
