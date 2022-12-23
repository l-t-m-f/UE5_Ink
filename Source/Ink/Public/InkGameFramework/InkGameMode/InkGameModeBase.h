#pragma once

#define DEBUG

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InkGameModeBase.generated.h"

UCLASS()
class INK_API AInkGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintGetter)
	APawn *GetMainPlayerInstance() const;

	UFUNCTION(BlueprintSetter)
	void SetMainPlayerInstance(APawn *Value);
	
private:
	UPROPERTY(VisibleAnywhere, Category="Key References",
		BlueprintGetter=GetMainPlayerInstance, BlueprintSetter=SetMainPlayerInstance)
	APawn *MainPlayerInstance;
	
};
