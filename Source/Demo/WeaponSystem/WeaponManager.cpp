#include "WeaponManager.h"
#include "Demo/Characters/BaseCharacter.h"

UWeaponManager::UWeaponManager()
{
}

void UWeaponManager::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<ABaseCharacter>(GetOwner());
}
