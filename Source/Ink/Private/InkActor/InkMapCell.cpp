#include "InkActor/InkMapCell.h"

AInkMapCell::AInkMapCell()
{
	PrimaryActorTick.bCanEverTick = true;
	SetCellMesh(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp")));
}

UStaticMeshComponent* AInkMapCell::GetCellMesh() const
{
	return CellMesh;
}

void AInkMapCell::SetCellMesh(UStaticMeshComponent* Value)
{
	CellMesh = Value;
}

void AInkMapCell::BeginPlay()
{
	Super::BeginPlay();	
}

void AInkMapCell::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}

