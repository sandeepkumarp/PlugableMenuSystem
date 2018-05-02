#pragma once

#include "CoreMinimal.h"
#include "MenuSystem/MenuWidget.h"

#include "MainMenu.generated.h"


class UButton;
class UWidgetSwitcher;
class UEditableTextBox;
/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
	UButton* Button_MM_Join;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_MM_Host;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_MM_Quit;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_JM_Cancel;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_JM_Join;
	
	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* EditableTextBox_ServerAddress;

	UFUNCTION()
	void OnButtonClicked_HostServer();

	UFUNCTION()
	void OnButtonClicked_JoinServer();

	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void CloseJoinMenu();

	UFUNCTION()
	void QuitGamePressed();

};
