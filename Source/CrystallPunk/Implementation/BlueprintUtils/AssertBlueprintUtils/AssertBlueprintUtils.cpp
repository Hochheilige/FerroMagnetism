#include "AssertBlueprintUtils.h"
#include "Kismet/KismetSystemLibrary.h"

void UAssertBlueprintUtils::AssertIsTrue(
	const bool testValue,
	EAssertResult& assertResult
)
{
	if (!testValue)
	{
		_AssertBlueprintUtilsLogAssertionFailed("Value is not true");
	}

	assertResult = GetAssertResultFromBool(testValue);
}

void UAssertBlueprintUtils::AssertIsFalse(
	const bool testValue,
	EAssertResult& assertResult
)
{
	if (testValue)
	{
		_AssertBlueprintUtilsLogAssertionFailed("Value is true");
	}

	assertResult = GetAssertResultFromBool(!testValue);
}

void UAssertBlueprintUtils::AssertInterfaceIsImplemented(
	UObject* testObject,
	const TSubclassOf<UInterface> testInterface,
	EAssertResult& assertResult
)
{
	const auto isInterfaceImplemented = UKismetSystemLibrary::DoesImplementInterface(testObject, testInterface);

	if(!isInterfaceImplemented)
	{
		_AssertBlueprintUtilsLogAssertionFailed("Interface is not implemented");
	}

	assertResult = GetAssertResultFromBool(isInterfaceImplemented);
}

void UAssertBlueprintUtils::AssertIsValid(
	UObject* testObject,
	EAssertResult& assertResult
)
{
	const auto isValid = BoolUtils::IsUObjectValid(testObject);

	if(!isValid)
	{
		_AssertBlueprintUtilsLogAssertionFailed("UObject is not valid");
	}
	
	assertResult = GetAssertResultFromBool(isValid);
}

void UAssertBlueprintUtils::AssertIsNotValid(
	UObject* testObject,
	EAssertResult& assertResult
)
{
	const auto isValid = BoolUtils::IsUObjectValid(testObject);

	if (isValid)
	{
		_AssertBlueprintUtilsLogAssertionFailed("UObject is valid");
	}

	assertResult = GetAssertResultFromBool(!isValid);
}

void UAssertBlueprintUtils::AssertClassIsValid(
	UClass* testClass,
	EAssertResult& assertResult
)
{
	const auto isValid = UKismetSystemLibrary::IsValidClass(testClass);

	if (!isValid)
	{
		_AssertBlueprintUtilsLogAssertionFailed("Class is not valid");
	}

	assertResult = GetAssertResultFromBool(isValid);
}

void UAssertBlueprintUtils::AssertNameIsValid(
	const FName& testName,
	EAssertResult& assertResult
)
{
	const auto isValid = !testName.IsNone();

	if (!isValid)
	{
		_AssertBlueprintUtilsLogAssertionFailed("Name is not valid");
	}

	assertResult = GetAssertResultFromBool(isValid);
}

void UAssertBlueprintUtils::AssertFloatIsEqual(
	const float leftHandValue,
	const float rightHandValue,
	EAssertResult& assertResult
)
{
	AssertValueIsEqual(leftHandValue, rightHandValue, assertResult);
}

void UAssertBlueprintUtils::AssertFloatIsGreater(
	const float leftHandValue,
	const float rightHandValue,
	EAssertResult& assertResult
)
{
	AssertValueIsGreater(leftHandValue, rightHandValue, assertResult);
}

void UAssertBlueprintUtils::AssertFloatIsGreaterOrEqual(
	const float leftHandValue,
	const float rightHandValue,
	EAssertResult& assertResult
)
{
	AssertValueIsGreaterOrEqual(leftHandValue, rightHandValue, assertResult);
}

void UAssertBlueprintUtils::AssertFloatIsLess(
	const float leftHandValue,
	const float rightHandValue,
	EAssertResult& assertResult
)
{
	AssertValueIsLess(leftHandValue, rightHandValue, assertResult);
}

void UAssertBlueprintUtils::AssertFloatIsLessOrEqual(
	const float leftHandValue,
	const float rightHandValue,
	EAssertResult& assertResult
)
{
	AssertValueIsLessOrEqual(leftHandValue, rightHandValue, assertResult);
}

void UAssertBlueprintUtils::AssertIntIsEqual(
	const int leftHandValue,
	const int rightHandValue,
	EAssertResult& assertResult
)
{
	AssertValueIsEqual(leftHandValue, rightHandValue, assertResult);
}

void UAssertBlueprintUtils::AssertIntIsGreater(
	const int leftHandValue,
	const int rightHandValue,
	EAssertResult& assertResult
)
{
	AssertValueIsGreater(leftHandValue, rightHandValue, assertResult);
}

void UAssertBlueprintUtils::AssertIntIsGreaterOrEqual(
	const int leftHandValue,
	const int rightHandValue,
	EAssertResult& assertResult
)
{
	AssertValueIsGreaterOrEqual(leftHandValue, rightHandValue, assertResult);
}

void UAssertBlueprintUtils::AssertIntIsLess(
	const int leftHandValue,
	const int rightHandValue,
	EAssertResult& assertResult
)
{
	AssertValueIsLess(leftHandValue, rightHandValue, assertResult);
}

void UAssertBlueprintUtils::AssertIntIsLessOrEqual(
	const int leftHandValue,
	const int rightHandValue,
	EAssertResult& assertResult
)
{
	AssertValueIsLessOrEqual(leftHandValue, rightHandValue, assertResult);
}

void UAssertBlueprintUtils::AssertUObjectIsEqual(
	UObject* leftHandValue,
	UObject* rightHandValue,
	EAssertResult& assertResult
)
{
	AssertValueIsEqual(leftHandValue, rightHandValue, assertResult);
}

EAssertResult UAssertBlueprintUtils::GetAssertResultFromBool(const bool isOk)
{
	return isOk ? EAssertResult::Ok : EAssertResult::Failed;
}
