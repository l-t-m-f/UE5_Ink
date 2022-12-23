#pragma once

#define DEBUG

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "InkDebugPawn.generated.h"

UCLASS()
class INK_API AInkDebugPawn final : public ADefaultPawn
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="Debug")
	int ExitDebugCamera();

protected:
	virtual void BeginPlay() override;
	
	
};
