#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"

#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetMenuInterface(IMenuInterface* MenuInterface);

	void Setup();

	void OnLevelRemovedFromWorld(ULevel * InLevel, UWorld * InWorld) override;

	void Teardown();

protected:
	IMenuInterface * MenuInterface;
	
	
};
