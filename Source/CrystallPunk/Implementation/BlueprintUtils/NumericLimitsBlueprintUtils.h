#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

#include "NumericLimitsBlueprintUtils.generated.h"

UCLASS()
class UNumericLimitsBlueprintUtils final : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static int GetMaxInt(AActor* actor);

	UFUNCTION(BlueprintPure)
	static int GetLowestInt(AActor* actor);

	UFUNCTION(BlueprintPure)
	static float GetMaxFloat(AActor* actor);

	UFUNCTION(BlueprintPure)
	static float GetLowestFloat(AActor* actor);

	UFUNCTION(BlueprintPure)
	static float GetWorldMax();

	UFUNCTION(BlueprintPure)
	static float GetHalfWorldMax();
};
