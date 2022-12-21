#include "InkGameFramework/InkCharacter.h"
#include "InkGameFramework/InkHUD.h"

// Sets default values
AInkCharacter::AInkCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInkCharacter::BeginPlay()
{
	Super::BeginPlay();
	AInkHUD::PrintToScreen("Character created (Custom CPP).");	
}

// Called every frame
void AInkCharacter::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AInkCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
