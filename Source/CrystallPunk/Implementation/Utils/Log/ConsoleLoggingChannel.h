#pragma once

#include "LoggingChannel.h"

/// <summary>
/// Console logging channel implementation.
/// Logs messages in Unreal Editor console
/// </summary>
class ConsoleLoggingChannel final : public LoggingChannel
{
public:
	ConsoleLoggingChannel(const FLogCategoryName defaultLogCategoryName);

protected:
	virtual void LogImplementation(
		FString&& message,
		const FLogCategoryName& category,
		const ELogVerbosity::Type verbosity
	) override;

private:
	FLogCategoryName _defaultLogCategoryName;
};
