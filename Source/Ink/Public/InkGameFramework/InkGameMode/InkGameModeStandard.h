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

private:
	UPROPERTY(VisibleAnywhere, BlueprintGetter=GetArenaComponent, BlueprintSetter=SetArenaComponent)
	UInkArenaComponent *ArenaComponent;

	// CONSTRUCTOR(S)
public:
	AInkGameModeStandard();
	
	// GETTER FUNCTIONS

public:
	UFUNCTION(BlueprintGetter)
	UInkArenaComponent *GetArenaComponent() const;
	
	// SETTER FUNCTIONS

private:
	UFUNCTION(BlueprintSetter)
	void SetArenaComponent(UInkArenaComponent *Value);

	// OVERRIDEN FUNCTIONS

protected:
	virtual void BeginPlay() override;	

	// CLASS FUNCTIONS
};
