#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponManager.generated.h"

class AWeaponBase;
class ABaseCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DEMO_API UWeaponManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UWeaponManager();

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<ABaseCharacter> PlayerCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<AWeaponBase> PrimaryWeapon = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<AWeaponBase> SecondaryWeapon = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	TMap<FName, TSoftObjectPtr<AWeaponBase>> WeaponInventory;
	
	virtual void BeginPlay() override;
};
