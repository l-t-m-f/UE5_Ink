#pragma once

#define DEBUG

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InkUserWidget.generated.h"

UCLASS()
class INK_API UInkUserWidget final : public UUserWidget
{
	GENERATED_BODY()
	
	// CLASS PROPERTIES	

	// CONSTRUCTOR(S)
	
	// GETTER FUNCTIONS
	
	// SETTER FUNCTIONS

	// OVERRIDEN FUNCTIONS

	// CLASS FUNCTIONS

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic,
		Category="User Interface (Custom)|Viewport", meta=(AdvancedDisplay = "ZOrder"))
	void AddToViewportAndLog(int32 ZOrder = 0);
};
