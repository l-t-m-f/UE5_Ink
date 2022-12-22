#include "InkComponent/InkArenaComponent.h"

UInkArenaComponent::UInkArenaComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

TArray<AInkMapCell *> UInkArenaComponent::GetCells()
{
	return Cells;
}

uint8 UInkArenaComponent::GetCellCountW() const
{
	return CellCountW;
}

uint8 UInkArenaComponent::GetCellCountH() const
{
	return CellCountH;
}

uint8 UInkArenaComponent::GetBufferBetweenCell() const
{
	return BufferBetweenCell;
}

int UInkArenaComponent::GetDistanceBetweenCell() const
{
	return DistanceBetweenCell;
}

TSubclassOf<AInkMapCell> UInkArenaComponent::GetCellClass() const
{
	return CellClass;
}

void UInkArenaComponent::SetCellClass(const TSubclassOf<AInkMapCell> Value)
{
	CellClass = Value;
}

void UInkArenaComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInkArenaComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UInkArenaComponent::InitCells()
{
	for(int i = 0; i < CellCountW; i++)
	{
		for(int j = 0; j < CellCountH; j++)
		{
			//GetCells().Push(CreateDefaultSubobject<AInkMapCell>(TEXT("Cell")));
			GetCells().Push(NewObject<AInkMapCell>(AInkMapCell::StaticClass()));
			CreateCell(i * GetDistanceBetweenCell() + (i * GetBufferBetweenCell()), j * GetDistanceBetweenCell() + (j * GetBufferBetweenCell()));
			AInkHUD::PrintfToScreen(TEXT("%d, %d: Cell created #%d"), i, j, (i + j));
		}
	}
}

void UInkArenaComponent::CreateCell(const int X, const int Y) const
{
	const FVector Position = FVector(X, Y, 25);
	if(CellClass)
	{
		GetWorld()->SpawnActor(CellClass, &Position);
	}
}
