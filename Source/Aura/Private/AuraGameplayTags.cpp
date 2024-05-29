// Copyright KittenGames


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	/*
	* Primary Attribute Tags
	*/
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("Attributes.Primary.Strength"), FString("Increases physical damage"));

	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"), FString("Increases magical damage"));

	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("Attributes.Primary.Resilience"), FString("Increases Armor and Armor Penetration"));

	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("Attributes.Primary.Vigor"), FString("Increases Health"));

	/*
	* Secondary Attribute Tags
	*/
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces damage taken, improves Block Chance"));

	GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("Attributes.Secondary.ArmorPenetration"), FString("Ignores percentage of enemy Armor, increases Critical Hit Chance"));

	GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("Attributes.Secondary.BlockChance"), FString("Chance to cut incoming damage in half"));

	GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitChance"), FString("Chance to double damage plus Critical Hit bonus"));

	GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitDamage"), FString("Bonus damage added when a Critical Hit is landed"));

	GameplayTags.Attributes_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitResistance"), FString("Reduces Critical Hit Chance from attacking enemies"));

	GameplayTags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("Attributes.Secondary.HealthRegeneration"), FString("Amount of Health regenerated every 1 second"));

	GameplayTags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("Attributes.Secondary.ManaRegeneration"), FString("Amount of Mana regenerated every 1 second"));

	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("Attributes.Secondary.MaxHealth"), FString("Maximum amount of Health"));

	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("Attributes.Secondary.MaxMana"), FString("Maximum amount of Mana"));

	/*
	* Input Tags
	*/
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("InputTag.LMB"), FString("Input tag for Left Mouse button"));

	GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("InputTag.RMB"), FString("Input tag for Right Mouse button"));

	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("InputTag.1"), FString("Input tag for 1 key"));

	GameplayTags.InputTag_2 = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("InputTag.2"), FString("Input tag for 2 key"));

	GameplayTags.InputTag_3 = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("InputTag.3"), FString("Input tag for 3 key"));

	GameplayTags.InputTag_4 = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("InputTag.4"), FString("Input tag for 4 key"));
}
