// Copyright KittenGames

#include "AbilitySystem/Data/LevelUpInfo.h"

int32 ULevelUpInfo::FindLevelForXP(int32 XP) const
{
	bool bSearching = true;
	int32 Level = 1;

	while (bSearching)
	{
		// LevelUpInfo[1] = Level 1 Information
		// LevelUpInfo[2] = Level 2 Information
		// LevelUpInfo[0] means nothing, just a placeholder for BP
		if (LevelUpInformation.Num() - 1 <= Level)
			return Level;

		if (XP >= LevelUpInformation[Level].LevelUpRequirement)
			++Level;
		else
			bSearching = false;
	}

	return Level;
}
