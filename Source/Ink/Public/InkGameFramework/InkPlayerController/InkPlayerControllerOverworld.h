#pragma once

#define DEBUG

#include "CoreMinimal.h"
#include "InkGameFramework/InkPlayerController/InkPlayerController.h"
#include "InkPlayerControllerOverworld.generated.h"

UCLASS()
class INK_API AInkPlayerControllerOverworld final : public AInkPlayerController
{
	GENERATED_BODY()
	
public:
	
protected:
	//Methods
	virtual void BeginPlay() override;

private:
	
};
