// Copyright KittenGames


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AttributeSet = WCParams.AttributeSet;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
}
