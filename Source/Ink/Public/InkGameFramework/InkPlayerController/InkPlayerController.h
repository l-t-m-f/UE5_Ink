#pragma once

#define DEBUG

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h" 
#include "InkGameFramework/InkHUD.h"
#include "InputMappingContext.h" 
#include "GameFramework/PlayerController.h"
#include "InkActor/InkDebugPawn.h"
#include "InkPlayerController.generated.h"

UCLASS()
class INK_API AInkPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	//Methods
	UFUNCTION(BlueprintGetter)
	TSoftObjectPtr<UInputMappingContext> GetInputMapping();

	UFUNCTION(BlueprintGetter)
	TSubclassOf<AInkDebugPawn> GetDebugPawnClass() const;
	
	UFUNCTION(BlueprintSetter)
	void SetInputMapping(const TSoftObjectPtr<UInputMappingContext> Value);

	UFUNCTION(BlueprintSetter)
	void SetDebugPawnClass(TSubclassOf<AInkDebugPawn> Value);

protected:
	//Methods
	UFUNCTION()
	void InitializeInput();
	
private:
	//Properties
	UPROPERTY(EditDefaultsOnly, Category="Input",
		BlueprintGetter=GetInputMapping, BlueprintSetter=SetInputMapping)
	TSoftObjectPtr<UInputMappingContext> InputMapping;

	UPROPERTY(EditAnywhere, Category="Debug",
		BlueprintGetter=GetDebugPawnClass, BlueprintSetter=SetDebugPawnClass)
	TSubclassOf<AInkDebugPawn> DebugPawnClass;
	
};
