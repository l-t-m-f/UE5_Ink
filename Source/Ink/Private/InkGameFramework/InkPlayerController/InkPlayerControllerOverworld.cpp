#include "InkGameFramework/InkPlayerController/InkPlayerControllerOverworld.h"

void AInkPlayerControllerOverworld::BeginPlay()
{
	Super::BeginPlay();
	InitializeInput();
}
