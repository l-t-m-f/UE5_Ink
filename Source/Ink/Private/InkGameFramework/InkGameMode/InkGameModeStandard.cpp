#include "InkGameFramework/InkGameMode/InkGameModeStandard.h"

AInkGameModeStandard::AInkGameModeStandard()
{
	SetArenaComponent(CreateDefaultSubobject<UInkArenaComponent>(TEXT("ArenaComp")));
}

UInkArenaComponent* AInkGameModeStandard::GetArenaComponent() const
{
	return ArenaComponent;
}

void AInkGameModeStandard::SetArenaComponent(UInkArenaComponent* Value)
{
	ArenaComponent = Value;
}

void AInkGameModeStandard::BeginPlay()
{
	Super::BeginPlay();
}
