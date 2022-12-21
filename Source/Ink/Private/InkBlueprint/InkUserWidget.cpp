#include "InkBlueprint/InkUserWidget.h"
#include "InkGameFramework/InkHUD.h"

void UInkUserWidget::AddToViewportAndLog(const int32 ZOrder)
{
	Super::AddToViewport(ZOrder);
	AInkHUD::PrintToScreen("User Widget added to Viewport (Custom CPP).");	
}
