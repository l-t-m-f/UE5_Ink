#include "InkActor/InkDebugPawn.h"

#include "InkEngine/InkGameInstance.h"
#include "InkGameFramework/InkHUD.h"
#include "InkGameFramework/InkGameMode/InkGameModeStandard.h"
#include "InkGameFramework/InkPlayerController/InkPlayerControllerOverworld.h"
#include "Kismet/GameplayStatics.h"

void AInkDebugPawn::BeginPlay()
{
	Super::BeginPlay();
	AInkHUD::PrintToScreen("Instigator is " + GetInstigator()->GetName());

	const APawn *OriginalPlayer = Cast<AInkGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()))->GetMainPlayerInstance();
	AInkHUD::PrintToScreen("Original player is " + OriginalPlayer->GetName());
}

int AInkDebugPawn::ExitDebugCamera()

{	APawn *OriginalPlayer = Cast<AInkGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()))->GetMainPlayerInstance();
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->Possess(OriginalPlayer);
	return 1;
}
