#pragma once

#define DEBUG

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "InkGameFramework/InkHUD.h"
#include "InkGameFramework/InkPlayerController/InkPlayerController.h"
#include "InkGameFramework/InkCharacter.h"
#include "InkGameFramework/InkGameMode/InkGameModeBase.h"
#include "InkGameFramework/InkGameState/InkGameStateBase.h"
#include "InkStaticFunctionLibrary.generated.h"

UCLASS()
class INK_API UInkStaticFunctionLibrary final : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	// CLASS PROPERTIES	

	// CONSTRUCTOR(S)
	
	// GETTER FUNCTIONS
	
	// SETTER FUNCTIONS

	// OVERRIDEN FUNCTIONS

	// CLASS FUNCTIONS

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ink|GameFramework",
		meta = (DeterminesOutputType = "GameModeClass"), meta = (WorldContext = "WorldContextObject"))
	static AInkGameModeBase *GetInkGameMode(const UObject *WorldContextObject, TSubclassOf<AInkGameModeBase> InkGameModeClass);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ink|GameFramework",
		meta = (DeterminesOutputType = "GameStateClass"), meta = (WorldContext = "WorldContextObject"))
	static AInkGameStateBase *GetInkGameState(const UObject *WorldContextObject, TSubclassOf<AInkGameStateBase> InkGameStateClass);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ink|GameFramework",
		meta = (DeterminesOutputType = "PlayerCharacterClass"), meta = (WorldContext = "WorldContextObject"))
	static AInkCharacter *GetInkPlayerCharacter(const UObject *WorldContextObject, TSubclassOf<AInkCharacter> InkPlayerCharacterClass);
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ink|GameFramework",
		meta = (DeterminesOutputType = "PlayerControllerClass"), meta = (WorldContext = "WorldContextObject"))
	static AInkPlayerController *GetInkPlayerController(const UObject *WorldContextObject, TSubclassOf<AInkPlayerController> InkPlayerControllerClass);
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ink|GameFramework",
		meta = (DeterminesOutputType = "PlayerControllerClass"), meta = (WorldContext = "WorldContextObject"))
	static AInkHUD *GetInkHUD(const UObject *WorldContextObject, TSubclassOf<AInkHUD> InkHUDClass);
	
};

inline AInkGameModeBase* UInkStaticFunctionLibrary::GetInkGameMode(
	const UObject* WorldContextObject, TSubclassOf<AInkGameModeBase> InkGameModeClass)
{
	const UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	AGameModeBase *GameMode = UGameplayStatics::GetGameMode(World);
	return Cast<AInkGameModeBase>(GameMode);
}

inline AInkGameStateBase* UInkStaticFunctionLibrary::GetInkGameState(
	const UObject* WorldContextObject, TSubclassOf<AInkGameStateBase> InkGameStateClass)
{
	const UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	AGameStateBase *GameState = UGameplayStatics::GetGameState(World);
	return Cast<AInkGameStateBase>(GameState);
}

inline AInkCharacter* UInkStaticFunctionLibrary::GetInkPlayerCharacter(
	const UObject* WorldContextObject, TSubclassOf<AInkCharacter> InkPlayerCharacterClass)
{
	const UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	ACharacter *PlayerCharacter = UGameplayStatics::GetPlayerCharacter(World, 0);
	return Cast<AInkCharacter>(PlayerCharacter);
}

inline AInkPlayerController* UInkStaticFunctionLibrary::GetInkPlayerController(
	const UObject* WorldContextObject, TSubclassOf<AInkPlayerController> InkPlayerControllerClass)
{
	const UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	APlayerController *PlayerController = UGameplayStatics::GetPlayerController(World, 0);
	return Cast<AInkPlayerController>(PlayerController);
}

inline AInkHUD* UInkStaticFunctionLibrary::GetInkHUD(const UObject* WorldContextObject,
	TSubclassOf<AInkHUD> InkHUDClass)
{
	const UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	AHUD *HUD = UGameplayStatics::GetPlayerController(World, 0)->GetHUD();
	return Cast<AInkHUD>(HUD);
}