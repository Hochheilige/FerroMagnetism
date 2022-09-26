#pragma once

#include "CrystallPunk/Contract/Constant/LogCategory.h"
#include "CrystallPunk/Implementation/Utils/FStringUtils.h"

/// <summary>
/// [Abstract] Logging channel base class
/// </summary>
class LoggingChannel
{
public:
	LoggingChannel() = default;

	virtual ~LoggingChannel() = default;

	/// <summary>
	/// Log message. Can specify category and verbosity.
	/// </summary>
	/// <typeparam name="T">Type of value to log</typeparam>
	/// <param name="value">Value to log</param>
	/// <param name="categoryName">[Optional] Category name</param>
	/// <param name="verbosity">[Optional] Verbosity</param>
	template<typename T>
	void Log(
		T&& value,
		const FLogCategoryName& categoryName = FName(),
		const ELogVerbosity::Type verbosity = ELogVerbosity::Display
	)
	{
		LogImplementation(
			Forward<FString>(FStringUtils::ToString(value)),
			categoryName,
			verbosity
		);
	}

	template<typename T>
	void LogWithDescription(
		FString&& description,
		T&& value,
		const FLogCategoryName& categoryName = FName(),
		const ELogVerbosity::Type verbosity = ELogVerbosity::Display
	)
	{
		LogImplementation(
			Forward<FString>(description + " " + FStringUtils::ToString(value)),
			categoryName,
			verbosity
		);
	}
	
	/// <summary>
	/// Log error message
	/// </summary>
	/// <typeparam name="T">Type of value to log</typeparam>
	/// <param name="value">Value to log</param>
	template<typename T>
	void LogError(
		T&& value
	)
	{
		LogImplementation(
			Forward<FString>(FStringUtils::ToString(value)),
			NAME_Error,
			ELogVerbosity::Error
		);
	}

	/// <summary>
	/// Log warning message
	/// </summary>
	/// <typeparam name="T">Type of value to log</typeparam>
	/// <param name="value">Value to log</param>
	template<typename T>
	void LogWarning(
		T&& value
	)
	{
		LogImplementation(
			Forward<FString>(FStringUtils::ToString(value)),
			NAME_Warning,
			ELogVerbosity::Warning
		);
	}

protected:
	///<summary>
	///[Template method] Implementation of how message will be logged (to screen, to file, etc.)
	///</summary>
	virtual void LogImplementation(
		FString&& message,
		const FLogCategoryName& categoryName,
		const ELogVerbosity::Type verbosity
	) = 0;
};
