#pragma once

#include "../BoolUtils.h"
#include "../Log/DevLogger.h"

#define _AssertUtilsAssertionFailed \
FString(__FUNCTION__) + FString(" | Line: ") + FStringUtils::ToString(__LINE__) + FString(" | Assertion failed | ")

#define _AssertUtilsLogAssertionFailed(message) \
auto assertionMessage = _AssertUtilsAssertionFailed + message; \
DevLogger::GetViewportLoggingChannel()->LogError(assertionMessage); \
DevLogger::GetConsoleLoggingChannel()->LogError(assertionMessage);

#define _AssertUtilsLogError(message) \
DevLogger::GetViewportLoggingChannel()->LogError(message); \
DevLogger::GetConsoleLoggingChannel()->LogError(message);

#define _AssertDefaultImplementationIsOverriden_Implementation(...) \
_AssertUtilsLogAssertionFailed("Default implementation is not overriden or base class implementation is called in derived class"); \
return __VA_ARGS__; \

#define _AssertReferenceIsValid_Implementation(reference, ...) \
if (!BoolUtils::IsReferenceValid(reference)) \
{\
	_AssertUtilsLogAssertionFailed("Reference is not valid."); \
	return __VA_ARGS__; \
};

#define _AssertReferenceIsNotValid_Implementation(reference, ...) \
if (BoolUtils::IsReferenceValid(reference)) \
{\
	_AssertUtilsLogAssertionFailed("Reference is valid."); \
	return __VA_ARGS__; \
};

#define _AssertUObjectPointerIsValid_Implementation(pointer, ...) \
if (!IsValid(pointer)) \
{\
	_AssertUtilsLogAssertionFailed("UObject pointer is not valid."); \
	return __VA_ARGS__; \
};

#define _AssertUObjectPointerIsNotValid_Implementation(pointer, ...) \
if (IsValid(pointer)) \
{\
	_AssertUtilsLogAssertionFailed("UObject pointer is valid."); \
	return __VA_ARGS__; \
};

#define _AssertSmartPointerIsValid_Implementation(smartPointer, ...) \
if (!BoolUtils::IsTrue(smartPointer.IsValid())) \
{ \
	_AssertUtilsLogAssertionFailed("Smart pointer is not valid"); \
	return __VA_ARGS__; \
};

#define _AssertSmartPointerIsNotValid_Implementation(smartPointer, ...) \
if (BoolUtils::IsTrue(smartPointer.IsValid())) \
{ \
	_AssertUtilsLogAssertionFailed("Smart pointer is valid"); \
	return __VA_ARGS__; \
};

#define _AssertIsNull_Implementation(pointer, ...) \
if (!BoolUtils::IsNull(pointer)) \
{\
	_AssertUtilsLogAssertionFailed("Value is not null."); \
	return __VA_ARGS__; \
};

#define _AssertIsNotNull_Implementation(pointer, ...) \
if (BoolUtils::IsNull(pointer)) \
{\
	_AssertUtilsLogAssertionFailed("Value is null."); \
	return __VA_ARGS__; \
};

#define _AssertStringIsNotEmpty_Implementation(value, ...) \
if (BoolUtils::IsStringEmpty(value)) \
{ \
	_AssertUtilsLogAssertionFailed("Value is empty"); \
	return __VA_ARGS__; \
};

#define _AssertNameIsAssigned_Implementation(value, ...) \
if (value.IsNone()) \
{ \
	_AssertUtilsLogAssertionFailed("Name is not assigned"); \
	return __VA_ARGS__; \
};

#define _AssertIsEqual_Implementation(leftHandValue, rightHandValue, ...) \
if (!BoolUtils::IsEqual(leftHandValue, rightHandValue)) \
{ \
	_AssertUtilsLogAssertionFailed("Values are not equal" + ); \
	_AssertUtilsLogError("Left hand value: " + FStringUtils::ToString(leftHandValue)); \
	_AssertUtilsLogError("Right hand value: " + FStringUtils::ToString(rightHandValue)); \
	return __VA_ARGS__; \
};

#define _AssertIsNotEqual_Implementation(leftHandValue, rightHandValue, ...) \
if (BoolUtils::IsEqual(leftHandValue, rightHandValue)) \
{ \
	_AssertUtilsLogAssertionFailed("Values are equal"); \
	_AssertUtilsLogError("Left hand value: " + FStringUtils::ToString(leftHandValue)); \
	_AssertUtilsLogError("Right hand value: " + FStringUtils::ToString(rightHandValue)); \
	return __VA_ARGS__; \
};

#define _AssertIsGreater_Implementation(leftHandValue, rightHandValue, ...) \
if (!BoolUtils::IsGreater(leftHandValue, rightHandValue)) \
{ \
	_AssertUtilsLogAssertionFailed("Value is not greater"); \
	_AssertUtilsLogError("Left hand value: " + FStringUtils::ToString(leftHandValue)); \
	_AssertUtilsLogError("Right hand value: " + FStringUtils::ToString(rightHandValue)); \
	return __VA_ARGS__; \
};

#define _AssertIsGreaterOrEqual_Implementation(leftHandValue, rightHandValue, ...) \
if (!BoolUtils::IsGreaterOrEqual(leftHandValue, rightHandValue)) \
{ \
	_AssertUtilsLogAssertionFailed("Value is not greater or equal"); \
	_AssertUtilsLogError("Left hand value: " + FStringUtils::ToString(leftHandValue)); \
	_AssertUtilsLogError("Right hand value: " + FStringUtils::ToString(rightHandValue)); \
	return __VA_ARGS__; \
};

#define _AssertIsLess_Implementation(leftHandValue, rightHandValue, ...) \
if (!BoolUtils::IsLess(leftHandValue, rightHandValue)) \
{ \
	_AssertUtilsLogAssertionFailed("Value is not less"); \
	_AssertUtilsLogError("Left hand value: " + FStringUtils::ToString(leftHandValue)); \
	_AssertUtilsLogError("Right hand value: " + FStringUtils::ToString(rightHandValue)); \
	return __VA_ARGS__; \
};

#define _AssertIsLessOrEqual_Implementation(leftHandValue, rightHandValue, ...) \
if (!BoolUtils::IsLessOrEqual(leftHandValue, rightHandValue)) \
{ \
	_AssertUtilsLogAssertionFailed("Value is not less or equal"); \
	_AssertUtilsLogError("Left hand value: " + FStringUtils::ToString(leftHandValue)); \
	_AssertUtilsLogError("Right hand value: " + FStringUtils::ToString(rightHandValue)); \
	return __VA_ARGS__; \
};

#define _AssertIsTrue_Implementation(value, ...) \
if (!BoolUtils::IsTrue(value)) \
{ \
	_AssertUtilsLogAssertionFailed("Value is not true"); \
	return __VA_ARGS__; \
};

#define _AssertIsFalse_Implementation(value, ...) \
if (!BoolUtils::IsFalse(value)) \
{ \
	_AssertUtilsLogAssertionFailed("Value is not false"); \
	return __VA_ARGS__; \
};

#define _AssertIndexIsInArrayBounds_Implementation(index, arr, ...) \
if (!BoolUtils::IsGreaterOrEqual(index, 0) || !BoolUtils::IsLessOrEqual(index, _weaponPivots.Num() - 1)) \
{ \
	_AssertUtilsLogAssertionFailed("Index is out of bounds of array."); \
	_AssertUtilsLogError("Index:" + FStringUtils::ToString(index)); \
	return __VA_ARGS__; \
};

#define _AssertContainerContainsElement_Implementation(container, element, ...) \
if (!container.Contains(element)) \
{ \
	_AssertUtilsLogAssertionFailed("Container does not contain element."); \
	return __VA_ARGS__; \
};

#define _AssertContainerDoesNotContainElement_Implementation(container, element, ...) \
if (container.Contains(element)) \
{ \
	_AssertUtilsLogAssertionFailed("Container contains element."); \
	return __VA_ARGS__; \
};

#define _AssertContainerIsNotEmpty_Implementation(container, ...) \
if (container.Num() <= 0) \
{ \
	_AssertUtilsLogAssertionFailed("Container is empty."); \
	return __VA_ARGS__; \
};

#define _AssertContainerIsEmpty_Implementation(container, ...) \
if (container.Num() > 0) \
{ \
	_AssertUtilsLogAssertionFailed("Container is not empty."); \
	return __VA_ARGS__; \
};

#define _AssertHasAuthority_Implementation(actor, ...) \
if (!BoolUtils::IsTrue(actor && actor->HasAuthority())) \
{ \
	_AssertUtilsLogAssertionFailed("Actor has no authority"); \
	return __VA_ARGS__; \
};

#define _AssertIsLocallyControlled_Implementation(actor, ...) \
if (!BoolUtils::IsTrue(actor && actor->IsLocallyControlled())) \
{ \
	_AssertUtilsLogAssertionFailed("Actor is not locally controlled"); \
	return __VA_ARGS__; \
};

#define _AssertUnrealInterfaceIsImplemented_Implementation(uObject, interfaceClass, ...) \
if (!BoolUtils::IsUnrealInterfaceImplemented(uObject, interfaceClass)) \
{ \
	_AssertUtilsLogAssertionFailed("Unreal interface is not implemented"); \
	return __VA_ARGS__; \
};

#define _AssertNativeInterfaceIsImplemented_Implementation(testObject, TInterface, ...) \
if(!Cast<TInterface>(testObject)) \
{ \
	_AssertUtilsLogAssertionFailed("Native interface is not implemented"); \
	return __VA_ARGS__; \
};
