#include "ConsoleLoggingChannel.h"

ConsoleLoggingChannel::ConsoleLoggingChannel(const FLogCategoryName defaultLogCategoryName)
{
	_defaultLogCategoryName = defaultLogCategoryName;
}

void ConsoleLoggingChannel::LogImplementation(
	FString&& message,
	const FLogCategoryName& categoryName,
	const ELogVerbosity::Type verbosity
)
{
	const auto logCategoryName = categoryName.IsNone() ? _defaultLogCategoryName : categoryName;
	FMsg::Logf(nullptr, 0, logCategoryName, verbosity, TEXT("%s"), *message);
}
