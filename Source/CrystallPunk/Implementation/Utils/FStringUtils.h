#pragma once

#include "Kismet/KismetStringLibrary.h"

/// <summary>
/// [Static] ToString conversion
/// </summary>
class FStringUtils
{
public:
	FStringUtils() = delete;

	// Scope: FString
	template <
		typename T,
		typename TEnableIf<
			TIsSame<T, FString>::Value
		, bool>::Type* = nullptr
	>
	static FString ToString(const T& value)
	{
		return value;
	}

	// Scope: const TCharType*
	template <
		typename T,
		typename TEnableIf<
		TAnd<
			TIsPointer<T>,
			TIsCharType<
				typename TRemoveCV<
					typename TRemovePointer<T>::Type
				>::Type>
		>::Value
		, bool>::Type* = nullptr
	>
	static FString ToString(const T& value)
	{
		return FString(value);
	}

	// Scope: const char[N] aka "string literal"
	//https://en.wikipedia.org/wiki/String_literal
	template <
		typename T,
		typename TEnableIf<
		TAnd<
			TIsArray<T>,
			TIsCharType<typename TRemoveExtent<T>::Type>
		>::Value
		, bool>::Type* = nullptr
	>
	static FString ToString(const T& value)
	{
		return FString(value);
	}

	// Scope: any class with implemented ToString()
	// Known classes: FVector, FVector2D, FQuat
	template <
		typename T,
		typename TEnableIf<
			TIsClass<T>::Value
			&& !TIsSame<T, FString>::Value
		, bool>::Type* = nullptr
	>
	static FString ToString(const T& value)
	{
		return value.ToString();
	}

	// Scope: bool
	template <
		typename T,
		typename TEnableIf<
			TIsSame<T, bool>::Value
		, bool>::Type* = nullptr
	>
	static FString ToString(const T& value)
	{
		return UKismetStringLibrary::Conv_BoolToString(value);
	}

	// Scope: TCharType
	template <
		typename T,
		typename TEnableIf<
		TIsCharType<T>::Value
		, bool>::Type* = nullptr
	>
	static FString ToString(const T& value)
	{

		FString fString{};
		fString.Append(&value);
		return fString;
	}

	// Scope: floating point numbers
	template <
		typename T,
		typename TEnableIf<
			TIsFloatingPoint<T>::Value
		, bool>::Type* = nullptr
	>
	static FString ToString(const T& value)
	{
		return UKismetStringLibrary::Conv_FloatToString(value);
	}

	// Scope: integer numbers
	template <
		typename T,
		typename TEnableIf<
			TIsArithmetic<T>::Value
			&& !TIsFloatingPoint<T>::Value
			&& !TIsSame<T, bool>::Value
			&& !TIsCharType<T>::Value
		, bool>::Type* = nullptr
	>
	static FString ToString(const T& value)
	{
		return UKismetStringLibrary::Conv_IntToString(value);
	}

	// Scope: UEnum
	template <
		typename T,
		typename TEnableIf<
			TIsEnumClass<T>::Value
		, bool>::Type* = nullptr
	>
	static FString ToString(const T value)
	{
		return EnumToString(value);
	}

	// Scope: enum / enum class
	template <
		typename T,
		typename TEnableIf<
			TIsEnum<T>::Value
			&& !TIsEnumClass<T>::Value
		, bool>::Type* = nullptr
	>
	static FString ToString(const T& value)
	{
		return ToString(static_cast<int>(value)) + FString(" [enum]");
	}

	template <
		typename T,
		typename TEnableIf<
			TIsEnumClass<T>::Value
		, bool>::Type* = nullptr
	>
	static FString EnumToString(const T value)
	{
		return StaticEnum<T>()->GetValueAsString(value);
	}

	template <
		typename T,
		typename TEnableIf<
			TIsEnumClass<T>::Value
		, bool>::Type* = nullptr
	>
	T StringToEnum(const FString& value)
	{
		return StaticEnum<T>()->GetValueByNameString(value);
	}
};
