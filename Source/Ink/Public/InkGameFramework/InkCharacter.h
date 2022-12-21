#pragma once

#define DEBUG

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InkCharacter.generated.h"

UCLASS()
class INK_API AInkCharacter final : public ACharacter
{
	GENERATED_BODY()
	
	// CLASS PROPERTIES	

	// CONSTRUCTOR(S)
public:
	AInkCharacter();
	
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
