#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"



bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return Success;

	if (!ensure(Button_MM_Host != nullptr)) return false;
	Button_MM_Host->OnClicked.AddDynamic(this, &UMainMenu::OnButtonClicked_HostServer);

	if (!ensure(Button_MM_Join != nullptr)) return false;
	Button_MM_Join->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);

	if (!ensure(Button_JM_Cancel != nullptr)) return false;
	Button_JM_Cancel->OnClicked.AddDynamic(this, &UMainMenu::CloseJoinMenu);

	if (!ensure(Button_JM_Join != nullptr)) return false;
	Button_JM_Join->OnClicked.AddDynamic(this, &UMainMenu::OnButtonClicked_JoinServer);

	return true;
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
		if (!ensure(EditableTextBox_ServerAddress != nullptr)) return;

		FString address = EditableTextBox_ServerAddress->GetText().ToString();
		MenuInterface->Join(address);
	}
}

void UMainMenu::OpenJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JoinMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(JoinMenu);
}

void UMainMenu::CloseJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(MainMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(MainMenu);
}
