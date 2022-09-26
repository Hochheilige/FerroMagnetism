#pragma once

#include "ActorBlueprintUtils.generated.h"

UCLASS()
class UActorBlueprintUtils final : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static APlayerController* GetPlayerControllerFromActor(AActor* actor);

	UFUNCTION(BlueprintPure)
	static APlayerController* GetPlayerControllerFromActorComponent(UActorComponent* actorComponent);

	UFUNCTION(BlueprintPure)
	static UObject* FindObjectByInterface(
		UObject* testObject,
		const TSubclassOf<UInterface> testInterface
	);

	UFUNCTION(BlueprintPure)
	static AActor* FindActorWithTag(
		UObject* worldContext,
		const FName& actorTag
	);

	UFUNCTION(BlueprintPure)
	static TArray<AActor*> FindAllActorsWithTag(
		UObject* worldContext,
		const FName& actorTag
	);

	UFUNCTION(BlueprintCallable)
	static UObject* SpawnActor(
		UObject* worldContext,
		TSubclassOf<AActor> actorSubClass,
		const FTransform& actorTransform
	);

	UFUNCTION(BlueprintCallable)
	static void DestroyActorAndAttachedActorsRecursive(AActor* actor);
};
