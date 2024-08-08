// Copyright KittenGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interaction/CombatInterface.h"
#include "AuraCharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;
class UGameplayAbility;
class UAnimMontage;
class UMaterialInstance;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

	/* Combat Interface */
	virtual FVector GetCombatSocketLocation_Implementation(const FGameplayTag& MontageTag) override;
	virtual bool IsDead_Implementation() const override { return bDead; };
	virtual AActor* GetAvatar_Implementation() override { return this; };
	virtual UAnimMontage* GetHitReactMontage_Implementation() override { return HitReactMontage; };
	virtual TArray<FTaggedMontage> GetAttackMontages_Implementation() override { return AttackMontages; };
	virtual void Die() override;
	/* end Combat Interface */

	UFUNCTION(NetMulticast, Reliable)
	virtual void MulticastHandleDeath();

	UPROPERTY(EditAnywhere, Category = Combat)
	TArray<FTaggedMontage> AttackMontages;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Combat)
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY(EditAnywhere, Category = Combat)
	FName WeaponTipSocketName;

	UPROPERTY(EditAnywhere, Category = Combat)
	FName LeftHandSocketName;

	UPROPERTY(EditAnywhere, Category = Combat)
	FName RightHandSocketName;

	UPROPERTY(EditAnywhere, Category = Combat)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere, Category = Combat)
	TObjectPtr<UAttributeSet> AttributeSet;

	virtual void InitAbilityActorInfo() {};

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Attributes)
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Attributes)
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Attributes)
	TSubclassOf<UGameplayEffect> DefaultVitalAttributes;

	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> DefaultAttributes, float Level) const;
	virtual void InitializeDefaultAttributes() const;

	void AddCharacterAbilities();

	bool bDead = false;

	/* Dissolve Effects */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dissolve Material")
	TObjectPtr<UMaterialInstance> DissolveMaterialInstance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dissolve Material")
	TObjectPtr<UMaterialInstance> WeaponDissolveMaterialInstance;

	void Dissolve();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartDissolveTimeline(UMaterialInstanceDynamic* DynamicMaterialInstance);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartWeaponDissolveTimeline(UMaterialInstanceDynamic* DynamicMaterialInstance);
	/* end Dissolve Effects */

private:

	UPROPERTY(EditAnywhere, Category = Abilities)
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditAnywhere, Category = Combat)
	TObjectPtr<UAnimMontage> HitReactMontage;
};
