#include "MainMenu.h"
#include "Components/Button.h"



bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return Success;

	if (!ensure(Button_Host != nullptr)) return false;
	Button_Host->OnClicked.AddDynamic(this, &UMainMenu::OnButtonClicked_HostServer);

	return true;
}

void UMainMenu::SetMenuInterface(IMenuInterface* MenuInterface)
{
	this->MenuInterface = MenuInterface;
}

void UMainMenu::Setup()
{
	this->AddToViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	APlayerController* PlayerController = World->GetFirstPlayerController(); //GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}

void UMainMenu::OnLevelRemovedFromWorld(ULevel * InLevel, UWorld * InWorld)
{
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);

	this->RemoveFromViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	APlayerController* PlayerController = World->GetFirstPlayerController(); //GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly InputModeData;

	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = false;
}

void UMainMenu::OnButtonClicked_HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Hosting Server"));
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
}

void UMainMenu::OnButtonClicked_JoinServer()
{
	if (MenuInterface != nullptr)
	{
		FString address = "192.168.0.107";
		//MenuInterface->Join(address);
	}
}
