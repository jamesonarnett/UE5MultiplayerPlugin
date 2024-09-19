

#include "Menu.h"
#include "Components/Button.h"
#include "MultiplayerSessionsSubsystem.h"

void UMenu::MenuSetup()
{
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	bIsFocusable = true;

	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();

		if (PlayerController)
		{
			FInputModeUIOnly InputModeData;
			InputModeData.SetWidgetToFocus(TakeWidget());
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(true);
		}
	}

	// Set subsystem
	UGameInstance* GameInstance = GetGameInstance();

	if (GameInstance)
	{
		MultiplayerSessionsSubsystem = GameInstance->GetSubsystem<UMultiplayerSessionsSubsystem>();
	}
}

bool UMenu::Initialize()
{
	if (!Super::Initialize()) return false;
	if (!HostButton || !JoinButton) return false;

	HostButton->OnClicked.AddDynamic(this, &UMenu::HostButtonClicked);
	JoinButton->OnClicked.AddDynamic(this, &UMenu::JoinButtonClicked);

	return true;
}

void UMenu::NativeDestruct()
{
	//MenuTearDown();

	Super::NativeDestruct();
}

void UMenu::HostButtonClicked()
{
	if (!MultiplayerSessionsSubsystem) 
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MultiplayerSessionsSubsystem not set! Cannot host game."));
		}
		return;
	}

	// temp hardcoding for testing
	MultiplayerSessionsSubsystem->CreateSession(4, FString("FreeForAll"));
}

void UMenu::JoinButtonClicked()
{
	if (!MultiplayerSessionsSubsystem)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MultiplayerSessionsSubsystem not set! Cannot join game."));
		}
		return;
	}

	//MultiplayerSessionsSubsystem->FindSessions(10);
}
