#include "InkGameFramework/InkGameMode/InkGameModeBase.h"


APawn* AInkGameModeBase::GetMainPlayerInstance() const
{
	return MainPlayerInstance;
}

void AInkGameModeBase::SetMainPlayerInstance(APawn *Value)
{
	MainPlayerInstance = Value;
}
