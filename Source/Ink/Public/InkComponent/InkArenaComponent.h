#pragma once

#define DEBUG

#include "InkCommon.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InkGameFramework/InkHUD.h"
#include "InkActor/InkMapCell.h"
#include "InkArenaComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INK_API UInkArenaComponent final : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UInkArenaComponent();
	
	UFUNCTION(BlueprintGetter)
	uint8 GetBufferBetweenCell() const;
	
	UFUNCTION(BlueprintGetter)
	TArray<AInkMapCell *> GetCells();

	UFUNCTION(BlueprintGetter)
	uint8 GetCellCountW() const;
	
	UFUNCTION(BlueprintGetter)
	uint8 GetCellCountH() const;

	UFUNCTION(BlueprintGetter)
	TSubclassOf<AInkMapCell> GetCellClass() const;
	
	UFUNCTION(BlueprintGetter)
	int GetDistanceBetweenCell() const;

	UFUNCTION(BlueprintSetter)
	void SetCellClass(TSubclassOf<AInkMapCell> Value);
	
	UFUNCTION(BlueprintCallable)
	void InitCells();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
		override;
	
protected:
	virtual void BeginPlay()
		override;
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetCellCountW)
	uint8 CellCountW = 7;
	
	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetCellCountH)
	uint8 CellCountH = 7;
	
	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetBufferBetweenCell)
	uint8 BufferBetweenCell = 2;
	
	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetDistanceBetweenCell)
	int DistanceBetweenCell = 100;
	
	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetCellClass, BlueprintSetter=SetCellClass)
	TSubclassOf<AInkMapCell> CellClass;
	
	UPROPERTY(BlueprintGetter=GetCells)
	TArray<AInkMapCell *> Cells;

	void CreateCell(const int X, const int Y) const;
		
};
