#pragma once

#include "LoggingChannel.h"
#include "LogSeverity.h"

/// <summary>
/// Viewport logging channel implementation
/// </summary>
class ViewportLoggingChannel final : public LoggingChannel
{
public:
	ViewportLoggingChannel(
		const FLogCategoryName defaultLogCategoryName,
		const int maxMessageCount, 
		const float timeToDisplay
	);

protected:
	virtual void LogImplementation(
		FString&& message,
		const FLogCategoryName& categoryName,
		const ELogVerbosity::Type verbosity
	) override;

private:
	FLogCategoryName _defaultLogCategoryName;

	int _maxMessageCount;

	float _timeToDisplay;
	
	int _lineIndex;

	bool _isMessageCountLimited;
	
	int _messageNumber = 0;

	TMap<ELogVerbosity::Type, LogSeverity> _verbosityToSeverity;
	
	static FColor GetSeverityColor(const LogSeverity severity);
};
