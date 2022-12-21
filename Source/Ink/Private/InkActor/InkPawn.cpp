#include "InkActor/InkPawn.h"
#include "InkGameFramework/InkHUD.h"

// Sets default values
AInkPawn::AInkPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInkPawn::BeginPlay()
{
	Super::BeginPlay();
	AInkHUD::PrintToScreen("Pawn created (Custom CPP).");		
}

// Called every frame
void AInkPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AInkPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
