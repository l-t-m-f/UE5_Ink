#include "InkGameFramework/InkCharacter.h"

#include "InkEngine/InkGameInstance.h"
#include "InkGameFramework/InkGameMode/InkGameModeStandard.h"
#include "InkGameFramework/InkPlayerController/InkPlayerControllerOverworld.h"
#include "InkKismet/InkStaticFunctionLibrary.h"
#include "Kismet/GameplayStatics.h" 

AInkCharacter::AInkCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	SetDebugStaticMesh1(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DebugStaticMeshComp1")));
	SetDebugStaticMesh2(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DebugStaticMeshComp2")));
	GetDebugStaticMesh1()->SetupAttachment(RootComponent);
	GetDebugStaticMesh2()->SetupAttachment(GetDebugStaticMesh1());
	SetCameraSpringArmComponent(CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArmComp")));
	GetCameraSpringArmComponent()->SetupAttachment(RootComponent);
	SetCameraComponent(CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp")));
	GetCameraComponent()->SetupAttachment(GetCameraSpringArmComponent());
}

UCameraComponent* AInkCharacter::GetCameraComponent() const
{
	return CameraComponent;
}

USpringArmComponent* AInkCharacter::GetCameraSpringArmComponent() const
{
	return CameraSpringArmComponent;
}

UStaticMeshComponent* AInkCharacter::GetDebugStaticMesh1() const
{
	return DebugStaticMesh1;
}

UStaticMeshComponent* AInkCharacter::GetDebugStaticMesh2() const
{
	return DebugStaticMesh2;
}

void AInkCharacter::BeginPlay()
{
	Super::BeginPlay();
	AInkHUD::PrintToScreen("Character created (Custom CPP).");
	Cast<AInkGameModeStandard>(UGameplayStatics::GetGameMode(GetWorld()))->SetMainPlayerInstance(this);
}

void AInkCharacter::SetDebugStaticMesh1(UStaticMeshComponent* Value)
{
	DebugStaticMesh1 = Value;
}

void AInkCharacter::SetDebugStaticMesh2(UStaticMeshComponent* Value)
{
	DebugStaticMesh2 = Value;
}

void AInkCharacter::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInkCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AInkCharacter::MoveForwardBackward(const float AxisValue)
{
	const FVector WorldDirection = GetCapsuleComponent()->GetForwardVector();
	AddMovementInput(WorldDirection, AxisValue);
}

void AInkCharacter::MoveLeftRight(const float AxisValue)
{
	const FVector WorldDirection = GetCapsuleComponent()->GetRightVector();
	AddMovementInput(WorldDirection, AxisValue);
}

void AInkCharacter::LookLeftRight(const float AxisValue) const
{
	AInkPlayerController *ThisPlayerController = Cast<AInkPlayerController>(GetController());
	FRotator ControlRotation = ThisPlayerController->GetControlRotation();
	ControlRotation.Yaw += AxisValue;
	ThisPlayerController->SetControlRotation(ControlRotation);
}

void AInkCharacter::LookUpDown(const float AxisValue) const
{
	GetCameraSpringArmComponent()->AddRelativeRotation(FRotator(AxisValue, 0, 0));
}

int AInkCharacter::EnterDebugCamera()
{
	const AInkPlayerController *PlayerController = Cast<AInkPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	const FVector Position = GetActorLocation();
	AActor *DebugCamera = GetWorld()->SpawnActor(PlayerController->GetDebugPawnClass(), &Position);
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->Possess(Cast<APawn>(DebugCamera));
	AInkHUD::PrintToScreen("Entered DebugCamera");
	return 1;
}

void AInkCharacter::SetCameraComponent(UCameraComponent* Value)
{
	CameraComponent = Value;
}

void AInkCharacter::SetCameraSpringArmComponent(USpringArmComponent* Value)
{
	CameraSpringArmComponent = Value;
}
