#include "ActorUtils.h"

UObject* ActorUtils::FindObjectByInterface(UObject* uObject, UClass* interfaceClass)
{
	_AssertIsNotNull(uObject, nullptr);

	if (uObject->GetClass()->ImplementsInterface(interfaceClass))
	{
		return uObject;
	}

	const auto actor = Cast<AActor>(uObject);

	if (!actor)
	{
		return nullptr;
	}

	for (const auto actorComponent : actor->GetComponents())
	{
		if (actorComponent && actorComponent->GetClass()->ImplementsInterface(interfaceClass))
		{
			return actorComponent;
		}
	}

	return nullptr;
}

void ActorUtils::DestroyActorAndAttachedActorsRecursive(AActor* actor)
{
	_AssertIsNotNull(actor);

	TArray<AActor*> attachedActors;
	actor->GetAttachedActors(attachedActors);

	for (const auto attachedActor : attachedActors)
	{
		DestroyActorAndAttachedActorsRecursive(attachedActor);
	}

	actor->Destroy();
}
