#pragma once

#include "Kismet/KismetStringLibrary.h"

class BoolUtils
{
public:
	/// <summary>
	/// Checks if reference is valid
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="reference"></param>
	/// <returns></returns>
	template <class T>
	static bool IsReferenceValid(T& reference);

	static bool IsUObjectValid(UObject* testUObject);

	/// <summary>
	/// Checks if pointer is null.
	/// </summary>
	/// <typeparam name="T">Nullable type</typeparam>
	/// <param name="rawPointer">Nullable value</param>
	/// <returns>True if null, false otherwise</returns>
	template <class T>
	static bool IsNull(const T rawPointer);

	/// <summary>
	/// Is container empty.
	/// </summary>
	/// <typeparam name="T">Template class should have Num() method.</typeparam>
	/// <param name="container">TArray, TMap, TSet, etc</param>
	/// <returns>True if empty, false otherwise</returns>
	template<class T>
	static bool IsContainerEmpty(const T container);

	/// <summary>
	/// Is string empty
	/// </summary>
	/// <param name="value">FString</param>
	/// <returns>True if empty, false otherwise</returns>
	template<class T>
	static bool IsStringEmpty(const FString& value);

	template<class T>
	static bool IsEqual(const T leftHandValue, const T rightHandValue);

	template<class T>
	static bool IsGreater(const T leftHandValue, const T rightHandValue);

	template<class T>
	static bool IsGreaterOrEqual(const T leftHandValue, const T rightHandValue);

	template<class T>
	static bool IsLess(const T leftHandValue, const T rightHandValue);

	template<class T>
	static bool IsLessOrEqual(const T leftHandValue, const T rightHandValue);

	static bool IsTrue(const bool value);

	static bool IsFalse(const bool value);

	static bool IsUnrealInterfaceImplemented(const UObject* uObject, const UClass* interfaceClass);
};

inline bool BoolUtils::IsTrue(const bool value)
{
	return value == true;
}

inline bool BoolUtils::IsFalse(const bool value)
{
	return value == false;
}

inline bool BoolUtils::IsUnrealInterfaceImplemented(const UObject* uObject, const UClass* interfaceClass)
{
	if(!uObject)
	{
		return false;
	}

	return uObject->GetClass()->ImplementsInterface(interfaceClass);
}

template <class T>
bool BoolUtils::IsReferenceValid(T& reference)
{
	return reference.IsValid();
}

template <class T>
bool BoolUtils::IsNull(const T rawPointer)
{
	return rawPointer == nullptr;
}

template <class T>
bool BoolUtils::IsContainerEmpty(const T container)
{
	return container.Num() > 0;
}

template <class T>
bool BoolUtils::IsStringEmpty(const FString& value)
{
	return UKismetStringLibrary::IsEmpty(value);
}

template <class T>
bool BoolUtils::IsEqual(const T leftHandValue, const T rightHandValue)
{
	return leftHandValue == rightHandValue;
}

inline bool BoolUtils::IsUObjectValid(UObject* testUObject)
{
	return IsValid(testUObject);
}

template <>
inline bool BoolUtils::IsEqual(const float leftHandValue, const float rightHandValue)
{
	return FMath::IsNearlyEqual(leftHandValue, rightHandValue);
}

template <class T>
bool BoolUtils::IsGreater(const T leftHandValue, const T rightHandValue)
{
	return leftHandValue > rightHandValue;
}

template <class T>
bool BoolUtils::IsGreaterOrEqual(const T leftHandValue, const T rightHandValue)
{
	return leftHandValue >= rightHandValue;
}

template <class T>
bool BoolUtils::IsLess(const T leftHandValue, const T rightHandValue)
{
	return leftHandValue < rightHandValue;
}

template <class T>
bool BoolUtils::IsLessOrEqual(const T leftHandValue, const T rightHandValue)
{
	return leftHandValue <= rightHandValue;
}
