#pragma once

class SmartPointerUtils
{
public:
	SmartPointerUtils() = delete;

	~SmartPointerUtils() = default;

	template<typename I, typename T, typename... TArgs>
	static typename
	TEnableIf<!TIsArray<T>::Value
	&& TIsDerivedFrom<T, I>::Value, TUniquePtr<I>>::Type
	MakeUnique(TArgs&&... Args)
	{
		return TUniquePtr<I>(new T(Forward<TArgs>(Args)...));
	}

	template<typename I, typename T>
	static typename
	TEnableIf<!TIsArray<T>::Value
	&& TIsDerivedFrom<T, I>::Value, TUniquePtr<I>>::Type
	MakeUnique(T* rawPtr)
	{
		return TUniquePtr<I>(rawPtr);
	}
};