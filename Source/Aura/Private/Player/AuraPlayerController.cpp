// Copyright KittenGames


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	APlayerController::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// check Context exists before using
	// if fails, game will crash, unlike with if check
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);

	Subsystem->AddMappingContext(AuraContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	APlayerController::SetupInputComponent();

	// will crash if the castchecked fails
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	// get forward direction based on controller
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);

	if (!CursorHit.bBlockingHit)
		return;

	// Last frame actor = this frame actor
	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	/*
	* Line trace from cursor will have several scenarios:
	* 
	* A. LastActor is null && ThisActor is valid
	*	- Highlight ThisActor
	* 
	* B. LastActor is null && ThisActor is null
	*	- Do nothing
	* 
	* C. LastActor is valid && ThisActor is null
	*	- Unhighlight LastActor
	* 
	* D. LastActor && ThisActor are valid, but not the same actor
	*	- Unhighlight LastActor and highlight ThisActor
	* 
	* E. LastActor && ThisActor are valid, and are the same actor
	*	- Do nothing
	*/

	if (!LastActor)
	{
		if (ThisActor)
		{
			ThisActor->HighlightActor();
		}
	}
	else //Actor in the last frame is valid
	{
		if (!ThisActor)
		{
			LastActor->UnHighlightActor();
		}
		else if((ThisActor && LastActor) && ThisActor != LastActor)
		{
			LastActor->UnHighlightActor();
			ThisActor->HighlightActor();
		}
	}
}
