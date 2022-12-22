#pragma once

#define DEBUG

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InkMapCell.generated.h"

UCLASS()
class INK_API AInkMapCell final : public AActor
{
	GENERATED_BODY()

public:
	AInkMapCell();

	UFUNCTION(BlueprintGetter)
	UStaticMeshComponent *GetCellMesh() const;
	
	UFUNCTION(BlueprintSetter)
	void SetCellMesh(UStaticMeshComponent *Value);
	
	virtual void Tick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;
	
private:
	
	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetCellMesh, BlueprintSetter=SetCellMesh)
	UStaticMeshComponent *CellMesh;
	
};
