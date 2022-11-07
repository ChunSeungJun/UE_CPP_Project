
#include "Player/CPlayer.h"
#include "Skill/C_SkillComponent.h"
#include "Kismet/GameplayStatics.h"

UC_SkillComponent::UC_SkillComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UC_SkillComponent::BeginPlay()
{
	Super::BeginPlay();

	owner = Cast<ACPlayer>(GetOwner());

}

void UC_SkillComponent::OnDestorySkill()
{
	owner->PlayAnimMontage(DestorySkillMontage);

}

void UC_SkillComponent::Begin_DestorySkill()
{
	FTransform transform = owner->GetMesh()->GetSocketTransform("EjectBullet");
	ASkill* skill = owner->GetWorld()->SpawnActorDeferred<ASkill>(DestorySkill, transform, owner);
	UGameplayStatics::FinishSpawningActor(skill, transform);
}




