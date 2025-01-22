#include "WeaponBase.h"
#include "WeaponInfo.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetSystemLibrary.h"

AWeaponBase::AWeaponBase()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DataTableObj(TEXT("/Game/Data/WeaponDataTable"));
	if (DataTableObj.Object) WeaponData.DataTable = DataTableObj.Object;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::Type::PhysicsOnly);
	WeaponMesh->SetCollisionResponseToAllChannels(ECR_Block);
	WeaponMesh->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	WeaponMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	SetRootComponent(WeaponMesh);

	PickupSphere = CreateDefaultSubobject<USphereComponent>("PickupSphere");
	PickupSphere->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	PickupSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	PickupSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	PickupSphere->SetGenerateOverlapEvents(true);
	PickupSphere->SetSphereRadius(70.0f);
	PickupSphere->ShapeColor = FColor::Cyan;
	PickupSphere->SetupAttachment(RootComponent);
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
}

void AWeaponBase::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	/******************************************************************
	* Load and set the weapon mesh from the data table if they're valid.
	*******************************************************************/
	
	if (WeaponData.DataTable == nullptr) return;

	if (const FWeaponData* Data = WeaponData.DataTable->FindRow<FWeaponData>(WeaponData.RowName, ""))
	{
		if (Data->Properties.Mesh == nullptr) return;

		UObject* LoadedObject = UKismetSystemLibrary::LoadAsset_Blocking(Data->Properties.Mesh);
		USkeletalMesh* LoadedMesh = Cast<USkeletalMesh>(LoadedObject);
		WeaponMesh->SetSkeletalMesh(LoadedMesh);
	}
}
