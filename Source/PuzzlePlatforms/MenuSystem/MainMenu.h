#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"

#include "MainMenu.generated.h"


class UButton;
/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IMenuInterface* MenuInterface);

protected:
	virtual bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
	UButton* Button_Join;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_Host;

	UFUNCTION()
	void OnButtonClicked_HostServer();

	UFUNCTION()
	void OnButtonClicked_JoinServer();

	IMenuInterface* MenuInterface;

};
