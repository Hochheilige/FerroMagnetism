#pragma once

#include "Engine/DataTable.h"
#include "LogBlueprintUtils.generated.h"

UCLASS()
class ULogBlueprintUtils final : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void Log(
		const FString& string
	);

	UFUNCTION(BlueprintCallable)
	static void LogWarning(
		const FString& string
	);

	UFUNCTION(BlueprintCallable)
	static void LogError(
		const FString& string
	);
};
