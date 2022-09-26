#pragma once

#include "LoggingChannel.h"

/// <summary>
/// [Static] Development logger.
/// Provides access to logging channels
/// </summary>
class DevLogger final
{
public:
	DevLogger() = delete;
	
	static LoggingChannel* GetConsoleLoggingChannel();

	static LoggingChannel* GetViewportLoggingChannel();

private:
	static TUniquePtr<LoggingChannel> _consoleLoggingChannel;

	static TUniquePtr<LoggingChannel> _viewportLoggingChannel;
};
