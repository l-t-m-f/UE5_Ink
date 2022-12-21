#pragma once

#define DEBUG

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InkPawn.generated.h"

UCLASS()
class INK_API AInkPawn : public APawn
{
	GENERATED_BODY()
	
	// CLASS PROPERTIES	

	// CONSTRUCTOR(S)
public:
	AInkPawn();
	
	// GETTER METHODS
	
	// SETTER METHODS

	// OVERRIDEN FUNCTIONS
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// CLASS FUNCTIONS
};
