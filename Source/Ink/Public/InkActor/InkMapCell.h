#pragma once

#define DEBUG

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InkMapCell.generated.h"

UCLASS()
class INK_API AInkMapCell final : public AActor
{
	GENERATED_BODY()
	
	// CLASS PROPERTIES	

	// CONSTRUCTOR(S)	
public:	
	AInkMapCell();
	
	// GETTER METHODS
	
	// SETTER METHODS
	
	//OVERRIDEN FUNCTIONS
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// CLASS FUNCTIONS
};
