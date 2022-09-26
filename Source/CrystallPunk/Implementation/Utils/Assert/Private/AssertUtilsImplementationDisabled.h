#pragma once

#define _AssertDefaultImplementationIsOverriden_Implementation(...) return __VA_ARGS__;

#define _AssertReferenceIsValid_Implementation(reference, ...)

#define _AssertReferenceIsNotValid_Implementation(reference, ...)

#define _AssertUObjectPointerIsValid_Implementation(pointer, ...)

#define _AssertUObjectPointerIsNotValid_Implementation(pointer, ...)

#define _AssertSmartPointerIsValid_Implementation(smartPointer, ...)

#define _AssertSmartPointerIsNotValid_Implementation(smartPointer, ...)

#define _AssertIsNull_Implementation(pointer, ...)

#define _AssertIsNotNull_Implementation(pointer, ...)

#define _AssertStringIsNotEmpty_Implementation(value, ...)

#define _AssertNameIsAssigned_Implementation(value, ...)

#define _AssertIsEqual_Implementation(leftHandValue, rightHandValue, ...)

#define _AssertIsNotEqual_Implementation(leftHandValue, rightHandValue, ...)

#define _AssertIsGreater_Implementation(leftHandValue, rightHandValue, ...)

#define _AssertIsGreaterOrEqual_Implementation(leftHandValue, rightHandValue, ...)

#define _AssertIsLess_Implementation(leftHandValue, rightHandValue, ...)

#define _AssertIsLessOrEqual_Implementation(leftHandValue, rightHandValue, ...)

#define _AssertIsTrue_Implementation(value, ...)

#define _AssertIsFalse_Implementation(value, ...)

#define _AssertIndexIsInArrayBounds_Implementation(index, arr, ...)

#define _AssertContainerContainsElement_Implementation(container, element, ...)

#define _AssertContainerDoesNotContainElement_Implementation(container, element, ...)

#define _AssertContainerIsNotEmpty_Implementation(container, ...)

#define _AssertContainerIsEmpty_Implementation(container, ...)

#define _AssertHasAuthority_Implementation(actor, ...)

#define _AssertIsLocallyControlled_Implementation(actor, ...)

#define _AssertUnrealInterfaceIsImplemented_Implementation(uObject, interfaceClass, ...)

#define _AssertNativeInterfaceIsImplemented_Implementation(testObject, TInterface, ...)
