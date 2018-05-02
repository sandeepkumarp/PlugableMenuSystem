#include "InGameMenu.h"
#include "Components/Button.h"


bool UInGameMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return Success;

	if (!ensure(Button_GM_Cancel != nullptr)) return false;
	Button_GM_Cancel->OnClicked.AddDynamic(this, &UInGameMenu::CancelPressedInGameMenu);

	if (!ensure(Button_GM_MainMenu != nullptr)) return false;
	Button_GM_MainMenu->OnClicked.AddDynamic(this, &UInGameMenu::QuitPressedInGameMenu);


	return true;
}

void UInGameMenu::CancelPressedInGameMenu()
{
	Teardown();
}

void UInGameMenu::QuitPressedInGameMenu()
{
	if (MenuInterface!=nullptr)
	{
		Teardown();
		MenuInterface->LoadMainMenu();
	}
}
