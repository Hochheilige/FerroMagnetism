#pragma once

#include "AssertResult.h"
#include "CrystallPunk/Implementation/Utils/BoolUtils.h"

#if UE_BUILD_SHIPPING
#include "Private/AssertBlueprintUtilsImplementationDisabled.h"	
#else
#include "Private/AssertBlueprintUtilsImplementationEnabled.h"	
#endif

#include "AssertBlueprintUtils.generated.h"

UCLASS()
class UAssertBlueprintUtils final : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertIsTrue(
		const bool testValue,
		EAssertResult& assertResult
	);

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertIsFalse(
		const bool testValue,
		EAssertResult& assertResult
	);

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertInterfaceIsImplemented(
		UObject* testObject,
		const TSubclassOf<UInterface> testInterface,
		EAssertResult& assertResult
	);

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertIsValid(
		UObject* testObject,
		EAssertResult& assertResult
	);

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertIsNotValid(
		UObject* testObject,
		EAssertResult& assertResult
	);

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertClassIsValid(
		UClass* testClass,
		EAssertResult& assertResult
	);

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertNameIsValid(
		const FName& testName,
		EAssertResult& assertResult
	);

	//Numeric: float

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertFloatIsEqual(
		const float leftHandValue,
		const float rightHandValue,
		EAssertResult& assertResult
	);

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertFloatIsGreater(
		const float leftHandValue,
		const float rightHandValue,
		EAssertResult& assertResult
	);

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertFloatIsGreaterOrEqual(
		const float leftHandValue,
		const float rightHandValue,
		EAssertResult& assertResult
	);

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertFloatIsLess(
		const float leftHandValue,
		const float rightHandValue,
		EAssertResult& assertResult
	);

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertFloatIsLessOrEqual(
		const float leftHandValue,
		const float rightHandValue,
		EAssertResult& assertResult
	);

	//Numeric: int

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertIntIsEqual(
		const int leftHandValue,
		const int rightHandValue,
		EAssertResult& assertResult
	);

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertIntIsGreater(
		const int leftHandValue,
		const int rightHandValue,
		EAssertResult& assertResult
	);

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertIntIsGreaterOrEqual(
		const int leftHandValue,
		const int rightHandValue,
		EAssertResult& assertResult
	);

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertIntIsLess(
		const int leftHandValue,
		const int rightHandValue,
		EAssertResult& assertResult
	);

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertIntIsLessOrEqual(
		const int leftHandValue,
		const int rightHandValue,
		EAssertResult& assertResult
	);

	//Pointer

	UFUNCTION(BlueprintCallable, meta = (ExpandEnumAsExecs = "assertResult"))
	static void AssertUObjectIsEqual(
		UObject* leftHandValue,
		UObject* rightHandValue,
		EAssertResult& assertResult
	);

private:
	static EAssertResult GetAssertResultFromBool(const bool isOk);

	template<typename T>
	static void AssertValueIsEqual(
		const T leftHandValue,
		const T rightHandValue,
		EAssertResult& assertResult
	);

	template<typename T>
	static void AssertValueIsGreater(
		const T leftHandValue,
		const T rightHandValue,
		EAssertResult& assertResult
	);

	template<typename T>
	static void AssertValueIsGreaterOrEqual(
		const T leftHandValue,
		const T rightHandValue,
		EAssertResult& assertResult
	);

	template<typename T>
	static void AssertValueIsLess(
		const T leftHandValue,
		const T rightHandValue,
		EAssertResult& assertResult
	);

	template<typename T>
	static void AssertValueIsLessOrEqual(
		const T leftHandValue,
		const T rightHandValue,
		EAssertResult& assertResult
	);
};

template <typename T>
void UAssertBlueprintUtils::AssertValueIsEqual(
	const T leftHandValue,
	const T rightHandValue,
	EAssertResult& assertResult
)
{
	const auto isValid = BoolUtils::IsEqual(leftHandValue, rightHandValue);

	if (!isValid)
	{
		_AssertBlueprintUtilsLogAssertionFailed("Value is not equal");
	}

	assertResult = GetAssertResultFromBool(isValid);
}

template <typename T>
void UAssertBlueprintUtils::AssertValueIsGreater(
	const T leftHandValue,
	const T rightHandValue,
	EAssertResult& assertResult
)
{
	const auto isValid = BoolUtils::IsGreater(leftHandValue, rightHandValue);

	if (!isValid)
	{
		_AssertBlueprintUtilsLogAssertionFailed("Value is not greater");
	}

	assertResult = GetAssertResultFromBool(isValid);
}

template <typename T>
void UAssertBlueprintUtils::AssertValueIsGreaterOrEqual(
	const T leftHandValue,
	const T rightHandValue,
	EAssertResult& assertResult
)
{
	const auto isValid = BoolUtils::IsGreaterOrEqual(leftHandValue, rightHandValue);

	if (!isValid)
	{
		_AssertBlueprintUtilsLogAssertionFailed("Value is not greater or equal");
	}

	assertResult = GetAssertResultFromBool(isValid);
}

template <typename T>
void UAssertBlueprintUtils::AssertValueIsLess(
	const T leftHandValue,
	const T rightHandValue,
	EAssertResult& assertResult
)
{
	const auto isValid = BoolUtils::IsLess(leftHandValue, rightHandValue);
	if (!isValid)
	{
		_AssertBlueprintUtilsLogAssertionFailed("Value is not less");
	}

	assertResult = GetAssertResultFromBool(isValid);
}

template <typename T>
void UAssertBlueprintUtils::AssertValueIsLessOrEqual(
	const T leftHandValue,
	const T rightHandValue,
	EAssertResult& assertResult
)
{
	const auto isValid = BoolUtils::IsLessOrEqual(leftHandValue, rightHandValue);

	if (!isValid)
	{
		_AssertBlueprintUtilsLogAssertionFailed("Value is not less or equal");
	}

	assertResult = GetAssertResultFromBool(isValid);
}
