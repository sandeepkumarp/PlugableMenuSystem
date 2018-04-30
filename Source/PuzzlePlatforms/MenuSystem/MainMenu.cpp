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
	if (MenuInterface!=nullptr)
	{
		FString address = "192.168.0.107";
		//MenuInterface->Join(address);
	}
}
