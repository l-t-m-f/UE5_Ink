#pragma once

#define DEBUG

#include "InkCommon.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InkActor/InkMapCell.h"
#include "InkArenaComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INK_API UInkArenaComponent final : public UActorComponent
{
	GENERATED_BODY()
	
	// CLASS PROPERTIES
public:
	UPROPERTY(BlueprintReadOnly)
	uint8 Width = 7;
	
public:
	UPROPERTY(BlueprintReadOnly)
	uint8 Height = 7;
	
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AInkMapCell> CellClass;
	
public:
	UPROPERTY(BlueprintReadOnly)
	TArray<AInkMapCell *> Cells;

	// CONSTRUCTOR(S)
public:	
	UInkArenaComponent();
	
	// GETTER METHODS
public:
	UFUNCTION(BlueprintGetter)
	TArray<AInkMapCell *> GetCells();

public:
	UFUNCTION(BlueprintGetter)
	uint8 GetWidth() const;
	
	UFUNCTION(BlueprintGetter)
	uint8 GetHeight() const;

	// SETTER METHODS

	// OVERRIDEN FUNCTIONS
protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// CLASS FUNCTIONS

public:
	UFUNCTION(BlueprintCallable)
	void InitCells();

private:
	void CreateCell(const uint8 X, const uint8 Y) const;
		
};
