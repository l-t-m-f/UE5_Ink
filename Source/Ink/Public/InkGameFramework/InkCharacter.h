#pragma once

#define DEBUG

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h" 
#include "Camera/CameraComponent.h"
#include "InkGameFramework/InkHUD.h"
#include "InkGameFramework/InkPlayerController/InkPlayerController.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "InkCharacter.generated.h"

UCLASS()
class INK_API AInkCharacter final : public ACharacter
{
	GENERATED_BODY()
	
public:
	//Constructor
	AInkCharacter();
	
	//Methods
	
	UFUNCTION(BlueprintGetter)
	UCameraComponent *GetCameraComponent() const;
	
	UFUNCTION(BlueprintGetter)
	USpringArmComponent *GetCameraSpringArmComponent() const;
	
	UFUNCTION(BlueprintGetter)
	UStaticMeshComponent *GetDebugStaticMesh1() const;

	UFUNCTION(BlueprintGetter)
	UStaticMeshComponent *GetDebugStaticMesh2() const;
	
	virtual void Tick(const float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable, Category="Controls|Movement")
	void MoveForwardBackward(const float AxisValue);
	
	UFUNCTION(BlueprintCallable, Category="Controls|Movement")
	void MoveLeftRight(const float AxisValue);
	
	UFUNCTION(BlueprintCallable, Category="Controls|Camera")
	void LookLeftRight(const float AxisValue) const;
	
	UFUNCTION(BlueprintCallable, Category="Controls|Camera")
	void LookUpDown(const float AxisValue) const;

protected:
	//Methods
	UFUNCTION(BlueprintSetter)
	void SetCameraComponent(UCameraComponent *Value);
	
	UFUNCTION(BlueprintSetter)
	void SetCameraSpringArmComponent(USpringArmComponent *Value);
	
	virtual void BeginPlay() override;

private:
	//Properties
	UPROPERTY(BlueprintGetter=GetCameraComponent, BlueprintSetter=SetCameraComponent,
		Category="Camera", VisibleAnywhere)
	UCameraComponent *CameraComponent;
	
	UPROPERTY(BlueprintGetter=GetCameraSpringArmComponent, BlueprintSetter=SetCameraSpringArmComponent,
		Category="Camera", VisibleAnywhere)
	USpringArmComponent *CameraSpringArmComponent;

	UPROPERTY(BlueprintGetter=GetDebugStaticMesh1, Category="Static Mesh", EditAnywhere)
	UStaticMeshComponent *DebugStaticMesh1;

	UPROPERTY(BlueprintGetter=GetDebugStaticMesh2, Category="Static Mesh", EditAnywhere)
	UStaticMeshComponent *DebugStaticMesh2;

	//Methods

	void SetDebugStaticMesh1(UStaticMeshComponent *Value);
	void SetDebugStaticMesh2(UStaticMeshComponent *Value);

};
