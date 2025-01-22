#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "WeaponInfo.generated.h"

class AWeaponBase;

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	None,
	AssaultRifle,
	SMG,
	Pistol
};

USTRUCT(BlueprintType)
struct FWeaponProperties
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<AWeaponBase> Class;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<USkeletalMesh> Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWeaponType WeaponType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Socket;

	FWeaponProperties() :
	Class(nullptr),
	Mesh(nullptr),
	WeaponType(EWeaponType::None),
	Name(FText::GetEmpty()),
	Socket(NAME_None)
	{}
};

USTRUCT(BlueprintType)
struct FWeaponStats
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ClipSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Distance;

	FWeaponStats() :
	MaxAmmo(0),
	ClipSize(0),
	FireRate(0.0f),
	Distance(0.0f)
	{}
};

USTRUCT(BlueprintType)
struct FWeaponData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FWeaponProperties Properties;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FWeaponStats Stats;
};
