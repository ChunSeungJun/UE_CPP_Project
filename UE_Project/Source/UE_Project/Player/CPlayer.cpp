#include "CPlayer.h"

#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/ArrowComponent.h"

#include "Camera/CameraComponent.h"


ACPlayer::ACPlayer()
{

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxWalkSpeed = 400;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(L"SkeletalMesh'/Game/Character/Mesh/SK_Mannequin.SK_Mannequin'");
	if (mesh.Succeeded()) GetMesh()->SetSkeletalMesh(mesh.Object);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	ConstructorHelpers::FClassFinder<UAnimInstance> anim(L"");
	if (anim.Succeeded()) GetMesh()->SetAnimClass(anim.Class);

	SpringArm->SetRelativeLocation(FVector(0, 0, 60));
	SpringArm->TargetArmLength = 200;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->SocketOffset = FVector(0, 60, 0);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}


void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayer::OnMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayer::OnMoveRight);
	PlayerInputComponent->BindAxis("HorizontalLook", this, &ACPlayer::OnHorizontalLook);
	PlayerInputComponent->BindAxis("VerticalLook", this, &ACPlayer::OnVerticalLook);

	PlayerInputComponent->BindAction("Run", EInputEvent::IE_Pressed, this, &ACPlayer::Run);
	PlayerInputComponent->BindAction("Run", EInputEvent::IE_Released, this, &ACPlayer::Walk);

}

void ACPlayer::OnMoveForward(float axis)
{
	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	// Controller 의 yaw 회전값을 저장합니다.
	FVector direction = FQuat(rotator).GetForwardVector().GetSafeNormal();
	// Controller 기준의 앞 방향을 1로 정규화된 값으로 저장합니다.

	AddMovementInput(direction, axis);
}

void ACPlayer::OnMoveRight(float axis)
{
	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetRightVector().GetSafeNormal();
	// Controller 기준의 오른쪽 방향을 1로 정규화된 값으로 저장합니다.

	AddMovementInput(direction, axis);
}

void ACPlayer::OnHorizontalLook(float axis)
{
	
	AddControllerYawInput(axis);

}

void ACPlayer::OnVerticalLook(float axis)
{
	AddControllerPitchInput(axis);
}

void ACPlayer::Run()
{
	GetCharacterMovement()->MaxWalkSpeed = 600;
}

void ACPlayer::Walk()
{
	GetCharacterMovement()->MaxWalkSpeed = 400;
}

