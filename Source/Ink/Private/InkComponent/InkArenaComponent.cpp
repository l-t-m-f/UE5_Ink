#include "InkComponent/InkArenaComponent.h"

#include "InkGameFramework/InkHUD.h"

UInkArenaComponent::UInkArenaComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

TArray<AInkMapCell *> UInkArenaComponent::GetCells()
{
	return Cells;
}

uint8 UInkArenaComponent::GetWidth() const
{
	return Width;
}

uint8 UInkArenaComponent::GetHeight() const
{
	return Height;
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
	for(int i = 0; i < Width; i++)
	{
		for(int j = 0; j < Height; j++)
		{
			//GetCells().Push(CreateDefaultSubobject<AInkMapCell>(TEXT("Cell")));
			GetCells().Push(NewObject<AInkMapCell>(AInkMapCell::StaticClass()));
			CreateCell(i * 100, j * 100);
			AInkHUD::PrintfToScreen(TEXT("%d, %d: Cell created #%d"), i, j, (i + j));
		}
	}
}

void UInkArenaComponent::CreateCell(const uint8 X, const uint8 Y) const
{
	const FVector Position = FVector(X, Y, 25);
	if(CellClass)
	{
		GetWorld()->SpawnActor(CellClass, &Position);
	}
}
