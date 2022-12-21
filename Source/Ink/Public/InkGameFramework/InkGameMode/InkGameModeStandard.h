#pragma once

#define DEBUG

#include "CoreMinimal.h"
#include "InkComponent/InkArenaComponent.h"
#include "InkGameFramework/InkGameMode/InkGameModeBase.h"
#include "InkGameModeStandard.generated.h"

UCLASS()
class INK_API AInkGameModeStandard final : public AInkGameModeBase
{
	GENERATED_BODY()
	
	// CLASS PROPERTIES

public:
	UPROPERTY(BlueprintReadOnly)
	UInkArenaComponent *ArenaComponent;

	// CONSTRUCTOR(S)
public:
	AInkGameModeStandard();
	
	// GETTER FUNCTIONS

protected:
	UFUNCTION(BlueprintGetter)
	UInkArenaComponent *GetArenaComponent() const;
	
	// SETTER FUNCTIONS

private:
	void SetArenaComponent(UInkArenaComponent *Value);

	// OVERRIDEN FUNCTIONS
	protected:
	virtual void BeginPlay() override;	

	// CLASS FUNCTIONS
};
