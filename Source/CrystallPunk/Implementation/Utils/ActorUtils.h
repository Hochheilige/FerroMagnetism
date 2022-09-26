#pragma once

#include "Assert/AssertUtils.h"

class ActorUtils final
{
public:
	ActorUtils() = delete;

	template<typename TPawn>
	static TPawn* GetPawnFromActor(
		AActor* actor
	);

	template<typename TPawn>
	static TPawn* GetPawnFromActorComponent(
		UActorComponent* actorComponent
	);

	template <typename TController>
	static TController* GetControllerFromActor(
		AActor* actor
	);

	template <typename TController>
	static TController* GetControllerFromActorComponent(
		UActorComponent* actorComponent
	);

	template<typename UInterface>
	static UObject* FindObjectByInterface(UObject* uObject)
	{
		const auto interfaceClass = UInterface::StaticClass();
		return FindObjectByInterface(uObject, interfaceClass);
	}

	static UObject* FindObjectByInterface(
		UObject* uObject,
		UClass* interfaceClass
	);

	static void DestroyActorAndAttachedActorsRecursive(AActor* actor);
};

template <typename TPawn>
TPawn* ActorUtils::GetPawnFromActor(AActor* actor)
{
	_AssertIsNotNull(actor, nullptr);

	const auto pawn = Cast<APawn>(actor);
	if (pawn)
	{
		return Cast<TPawn>(pawn);
	}

	const auto controller = Cast<AController>(actor);
	if (!controller)
	{
		return nullptr;
	}

	return Cast<TPawn>(controller->GetPawn());
}

template <typename TPawn>
TPawn* ActorUtils::GetPawnFromActorComponent(UActorComponent* actorComponent)
{
	_AssertIsNotNull(actorComponent, nullptr);

	const auto owner = actorComponent->GetOwner();
	if(!owner)
	{
		return nullptr;
	}

	return GetPawnFromActor<TPawn>(owner);
}

template <typename TController>
TController* ActorUtils::GetControllerFromActor(AActor* actor)
{
	_AssertIsNotNull(actor, nullptr);

	const auto controller = Cast<TController>(actor);
	if (controller)
	{
		return controller;
	}

	const auto pawn = Cast<APawn>(actor);
	if (!pawn)
	{
		return nullptr;
	}

	return pawn->GetController<TController>();
}

template <typename TController>
TController* ActorUtils::GetControllerFromActorComponent(UActorComponent* actorComponent)
{
	_AssertIsNotNull(actorComponent, nullptr);

	const auto owner = actorComponent->GetOwner();
	if (!owner)
	{
		return nullptr;
	}

	return GetControllerFromActor<TController>(owner);
}
