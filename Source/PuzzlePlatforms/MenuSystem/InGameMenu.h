#pragma once

#include "CoreMinimal.h"
#include "MenuSystem/MenuWidget.h"
#include "InGameMenu.generated.h"


class UButton;

/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API UInGameMenu : public UMenuWidget
{
	GENERATED_BODY()


protected:
	virtual bool Initialize() override;

private:

	UPROPERTY(meta = (BindWidget))
	UButton* Button_GM_Cancel;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_GM_MainMenu;

	UFUNCTION()
	void CancelPressedInGameMenu();

	UFUNCTION()
	void QuitPressedInGameMenu();
};
