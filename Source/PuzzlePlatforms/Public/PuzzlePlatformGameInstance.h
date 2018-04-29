#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzlePlatformGameInstance.generated.h"

class UUserWidget;
/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UPuzzlePlatformGameInstance(const FObjectInitializer & ObjectInitializer);

	virtual void Init();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);

	UFUNCTION(BlueprintCallable, Exec)
	void LoadMenu();

private:
	TSubclassOf<UUserWidget> MenuClass;

};

