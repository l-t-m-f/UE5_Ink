#include "InkGameFramework/InkCharacter.h"

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

void AInkCharacter::SetCameraComponent(UCameraComponent* Value)
{
	CameraComponent = Value;
}

void AInkCharacter::SetCameraSpringArmComponent(USpringArmComponent* Value)
{
	CameraSpringArmComponent = Value;
}
