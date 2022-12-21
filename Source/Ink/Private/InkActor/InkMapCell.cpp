#include "InkActor/InkMapCell.h"

AInkMapCell::AInkMapCell()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AInkMapCell::BeginPlay()
{
	Super::BeginPlay();	
}

void AInkMapCell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

