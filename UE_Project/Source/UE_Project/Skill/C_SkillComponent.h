
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "C_SkillComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE_PROJECT_API UC_SkillComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		class UAnimMontage* DestorySkillMontage;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ASkill> DestorySkill;

private:
	class ACPlayer* owner;

public:
	UC_SkillComponent();

protected:
	virtual void BeginPlay() override;

public:
	void OnDestorySkill();

	UFUNCTION()
		void Begin_DestorySkill();
};
