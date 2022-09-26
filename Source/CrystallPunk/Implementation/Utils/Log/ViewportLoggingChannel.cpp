#include "ViewportLoggingChannel.h"

#include "Kismet/KismetStringLibrary.h"

ViewportLoggingChannel::ViewportLoggingChannel(
	const FLogCategoryName defaultLogCategoryName,
	const int maxMessageCount,
	const float timeToDisplay
)
{
	_defaultLogCategoryName = defaultLogCategoryName;
	_maxMessageCount = maxMessageCount;
	_timeToDisplay = timeToDisplay;
	_isMessageCountLimited = maxMessageCount >= 1;
	_lineIndex = _isMessageCountLimited ? 0 : -1;
	_verbosityToSeverity.Add(ELogVerbosity::Error, LogSeverity::Error);
	_verbosityToSeverity.Add(ELogVerbosity::Warning, LogSeverity::Warning);
}

void ViewportLoggingChannel::LogImplementation(
	FString&& message,
	const FLogCategoryName& categoryName,
	const ELogVerbosity::Type verbosity
)
{
	_messageNumber++;

	if (!GEngine)
	{
		return;
	}

	auto severity = LogSeverity::Debug;
	if (_verbosityToSeverity.Contains(verbosity))
	{
		severity = _verbosityToSeverity[verbosity];
	}

	const auto logCategoryName = categoryName.IsNone() ? _defaultLogCategoryName : categoryName;
	auto const finalMessage =
		"[" + UKismetStringLibrary::Conv_IntToString(_messageNumber) + "] " +
		"[" + logCategoryName.ToString() + "] " +
		message;
	auto const color = GetSeverityColor(severity);
	GEngine->AddOnScreenDebugMessage(_lineIndex, _timeToDisplay, color, finalMessage);

	if (!_isMessageCountLimited)
	{
		return;
	}

	_lineIndex++;

	if (_lineIndex >= _maxMessageCount)
	{
		_lineIndex = 0;
	}
}

FColor ViewportLoggingChannel::GetSeverityColor(const LogSeverity severity)
{
	switch (severity)
	{
	case LogSeverity::Warning:
		return FColor::Orange;
	case LogSeverity::Error:
		return FColor::Red;
	default:
		return FColor::Emerald;
	};
}
