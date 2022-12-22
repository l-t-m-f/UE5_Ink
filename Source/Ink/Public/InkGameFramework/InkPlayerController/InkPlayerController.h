#pragma once

#define DEBUG

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h" 
#include "InkGameFramework/InkHUD.h"
#include "InputMappingContext.h" 
#include "GameFramework/PlayerController.h"
#include "InkPlayerController.generated.h"

UCLASS()
class INK_API AInkPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	//Methods
	UFUNCTION(BlueprintGetter)
	TSoftObjectPtr<UInputMappingContext> GetInputMapping();
	
	UFUNCTION(BlueprintSetter)
	void SetInputMapping(const TSoftObjectPtr<UInputMappingContext> Value);

protected:
	//Methods
	UFUNCTION()
	void InitializeInput();
	
private:
	//Properties
	UPROPERTY(EditDefaultsOnly, Category="Input",
		BlueprintGetter=GetInputMapping, BlueprintSetter=SetInputMapping)
	TSoftObjectPtr<UInputMappingContext> InputMapping;
	
};
