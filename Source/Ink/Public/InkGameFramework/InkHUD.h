#pragma once

#define DEBUG

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InkBlueprint/InkUserWidget.h"
#include "InkHUD.generated.h"

UCLASS()
class INK_API AInkHUD final : public AHUD
{
	GENERATED_BODY()
	
	// CLASS PROPERTIES

private:
	TMap<FName, TArray<UInkUserWidget *>> Widgets;

	// CONSTRUCTOR(S)
	
	// GETTER FUNCTIONS
	
	// SETTER FUNCTIONS

	// OVERRIDEN FUNCTIONS

	// CLASS FUNCTIONS

	public:
	static void PrintToScreen(const FString Text);

public:
	template<typename FmtType, typename... Types>
	static void PrintfToScreen(const FmtType& FormatString, Types... Values);
};


template <typename FmtType, typename ... Types>
void AInkHUD::PrintfToScreen(const FmtType& FormatString, Types... Values)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(FormatString, Values...));
}

inline void AInkHUD::PrintToScreen(const FString Text)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, Text);
}
