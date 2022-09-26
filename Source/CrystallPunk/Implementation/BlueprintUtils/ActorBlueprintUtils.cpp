#include "ActorBlueprintUtils.h"
#include "EngineUtils.h"
#include "CrystallPunk/Implementation/Utils/ActorUtils.h"
#include "Kismet/GameplayStatics.h"

APlayerController* UActorBlueprintUtils::GetPlayerControllerFromActor(AActor* actor)
{
	return ActorUtils::GetControllerFromActor<APlayerController>(actor);
}

APlayerController* UActorBlueprintUtils::GetPlayerControllerFromActorComponent(UActorComponent* actorComponent)
{
	return ActorUtils::GetControllerFromActorComponent<APlayerController>(actorComponent);
}

UObject* UActorBlueprintUtils::FindObjectByInterface(
	UObject* testObject,
	const TSubclassOf<UInterface> testInterface
)
{
	const auto testInterfaceClass = testInterface->GetDefaultObject()->GetClass();
	return ActorUtils::FindObjectByInterface(testObject, testInterfaceClass);
}

AActor* UActorBlueprintUtils::FindActorWithTag(UObject* worldContext, const FName& actorTag)
{
	_AssertIsNotNull(worldContext, nullptr);
	const auto world = worldContext->GetWorld();
	_AssertIsNotNull(world, nullptr);

	for (TActorIterator<AActor> actorIterator(world, AActor::StaticClass()); actorIterator; ++actorIterator)
	{
		const auto actor = *actorIterator;
		if (actor->Tags.Contains(actorTag))
		{
			return actor;
		}
	}

	return nullptr;
}

TArray<AActor*> UActorBlueprintUtils::FindAllActorsWithTag(UObject* worldContext, const FName& actorTag)
{
	TArray<AActor*> actorsWithTag;
	_AssertIsNotNull(worldContext, actorsWithTag);
	const auto world = worldContext->GetWorld();
	_AssertIsNotNull(world, actorsWithTag);

	for (TActorIterator<AActor> actorIterator(world, AActor::StaticClass()); actorIterator; ++actorIterator)
	{
		auto actor = *actorIterator;
		if (actor->Tags.Contains(actorTag))
		{
			actorsWithTag.Add(actor);
		}
	}

	return actorsWithTag;
}

UObject* UActorBlueprintUtils::SpawnActor(
	UObject* worldContext,
	TSubclassOf<AActor> actorSubClass,
	const FTransform& actorTransform
)
{
	_AssertIsNotNull(worldContext, nullptr);
	const auto world = worldContext->GetWorld();
	_AssertIsNotNull(world, nullptr);
	const auto actorClass = actorSubClass->GetDefaultObject()->GetClass();
	_AssertIsNotNull(actorClass, nullptr);
	const auto actor = world->SpawnActor(actorClass, &actorTransform);
	return actor;
}

void UActorBlueprintUtils::DestroyActorAndAttachedActorsRecursive(AActor* actor)
{
	_AssertIsNotNull(actor);
	ActorUtils::DestroyActorAndAttachedActorsRecursive(actor);
}
