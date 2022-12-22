#include "InkGameFramework/InkPlayerController/InkPlayerController.h"

TSoftObjectPtr<UInputMappingContext> AInkPlayerController::GetInputMapping()
{
	return InputMapping;
}

void AInkPlayerController::SetInputMapping(const TSoftObjectPtr<UInputMappingContext> Value)
{
	InputMapping = Value;
}

void AInkPlayerController::InitializeInput()
{
	if(const ULocalPlayer *LocalPlayer = Cast<ULocalPlayer>(Player))
	{
		if(UEnhancedInputLocalPlayerSubsystem *InputSystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if(!GetInputMapping().IsNull())
			{
				constexpr int32 Priority = 0;
				InputSystem->AddMappingContext(GetInputMapping().LoadSynchronous(), Priority);
				AInkHUD::PrintfToScreen(TEXT("Input mapping is set"));
			}
			else
			{
				AInkHUD::PrintfToScreen(TEXT("Input mapping is null"));
			}
		}
		else
		{
			AInkHUD::PrintfToScreen(TEXT("Getting Subsystem failed"));
		}
	}
	else
	{
		AInkHUD::PrintfToScreen(TEXT("Cast of Local Player failed"));
	}
}
