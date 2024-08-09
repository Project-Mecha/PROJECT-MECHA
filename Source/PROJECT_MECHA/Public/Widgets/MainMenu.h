// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_MECHA_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	TObjectPtr<class UPROJECTMECHA_Gameinstance> GameInstance;
	
private:
	UPROPERTY( meta = (BindWidget) )
	class UButton* LoginButton;

protected:
	UFUNCTION()
	void LoginButtonClicked();
};
