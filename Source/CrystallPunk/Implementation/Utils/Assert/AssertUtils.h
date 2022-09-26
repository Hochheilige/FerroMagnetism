#pragma once

#if UE_BUILD_SHIPPING
	#include "Private/AssertUtilsImplementationDisabled.h"	
#else
	#include "Private/AssertUtilsImplementationEnabled.h"	
#endif

#define _AssertDefaultImplementationIsOverriden(...)\
		_AssertDefaultImplementationIsOverriden_Implementation(__VA_ARGS__);

#define _AssertReferenceIsValid(reference, ...)\
		_AssertReferenceIsValid_Implementation (reference, __VA_ARGS__)

#define _AssertReferenceIsNotValid(reference, ...)\
		_AssertReferenceIsNotValid_Implementation (reference, __VA_ARGS__)

#define _AssertUObjectPointerIsValid(pointer, ...)\
		_AssertUObjectPointerIsValid_Implementation(pointer, __VA_ARGS__)

#define _AssertUObjectPointerIsNotValid(pointer, ...)\
		_AssertUObjectPointerIsNotValid_Implementation(pointer, __VA_ARGS__)

#define _AssertSmartPointerIsValid(smartPointer, ...)\
		_AssertSmartPointerIsValid_Implementation(smartPointer, __VA_ARGS__)

#define _AssertSmartPointerIsNotValid(smartPointer, ...)\
		_AssertSmartPointerIsNotValid_Implementation(smartPointer, __VA_ARGS__)

#define _AssertIsNull(pointer, ...)\
		_AssertIsNull_Implementation(pointer, __VA_ARGS__)

#define _AssertIsNotNull(pointer, ...)\
		_AssertIsNotNull_Implementation(pointer, __VA_ARGS__)

#define _AssertStringIsNotEmpty(value, ...)\
		_AssertStringIsNotEmpty_Implementation(value, __VA_ARGS__)

#define _AssertNameIsAssigned(value, ...)\
		_AssertNameIsAssigned_Implementation(value, __VA_ARGS__);

#define _AssertIsEqual(leftHandValue, rightHandValue, ...)\
		_AssertIsEqual_Implementation(leftHandValue, rightHandValue, __VA_ARGS__)

#define _AssertIsNotEqual(leftHandValue, rightHandValue, ...)\
		_AssertIsNotEqual_Implementation(leftHandValue, rightHandValue, __VA_ARGS__)

#define _AssertIsGreater(leftHandValue, rightHandValue, ...)\
		_AssertIsGreater_Implementation(leftHandValue, rightHandValue, __VA_ARGS__)

#define _AssertIsGreaterOrEqual(leftHandValue, rightHandValue, ...)\
		_AssertIsGreaterOrEqual_Implementation(leftHandValue, rightHandValue, __VA_ARGS__)

#define _AssertIsLess(leftHandValue, rightHandValue, ...)\
		_AssertIsLess_Implementation(leftHandValue, rightHandValue, __VA_ARGS__)

#define _AssertIsLessOrEqual(leftHandValue, rightHandValue, ...)\
		_AssertIsLessOrEqual_Implementation(leftHandValue, rightHandValue, __VA_ARGS__)

#define _AssertIsTrue(value, ...)\
		_AssertIsTrue_Implementation(value, __VA_ARGS__)

#define _AssertIsFalse(value, ...)\
		_AssertIsFalse_Implementation(value, __VA_ARGS__)

#define _AssertIndexIsInArrayBounds(index, arr, ...)\
		_AssertIndexIsInArrayBounds_Implementation(index, arr, __VA_ARGS__)

#define _AssertContainerContainsElement(container, element, ...)\
		_AssertContainerContainsElement_Implementation(container, element, __VA_ARGS__)

#define _AssertContainerDoesNotContainElement(container, element, ...)\
		_AssertContainerDoesNotContainElement_Implementation(container, element, __VA_ARGS__)

#define _AssertContainerIsNotEmpty(container, ...)\
		_AssertContainerIsNotEmpty_Implementation(container, __VA_ARGS__)

#define _AssertContainerIsEmpty(container, ...)\
		_AssertContainerIsEmpty_Implementation(container, __VA_ARGS__)

#define _AssertHasAuthority(actor, ...)\
		_AssertHasAuthority_Implementation(actor, __VA_ARGS__)

#define _AssertIsLocallyControlled(actor, ...)\
		_AssertIsLocallyControlled_Implementation(actor, __VA_ARGS__)

#define _AssertUnrealInterfaceIsImplemented(uObject, interfaceClass, ...) \
		_AssertUnrealInterfaceIsImplemented_Implementation(uObject, interfaceClass, __VA_ARGS__)

#define _AssertNativeInterfaceIsImplemented(uObject, TInterface, ...) \
		_AssertNativeInterfaceIsImplemented_Implementation(uObject, TInterface, __VA_ARGS__)
