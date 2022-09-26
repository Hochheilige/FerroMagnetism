#include "DevLogger.h"

#include "ConsoleLoggingChannelFactory.h"
#include "ViewportLoggingChannelFactory.h"

TUniquePtr<LoggingChannel> DevLogger::_consoleLoggingChannel = nullptr;

TUniquePtr<LoggingChannel> DevLogger::_viewportLoggingChannel = nullptr;

LoggingChannel* DevLogger::GetConsoleLoggingChannel()
{
	if (!_consoleLoggingChannel)
	{
		ConsoleLoggingChannelFactory factory;
		_consoleLoggingChannel = TUniquePtr<LoggingChannel>(factory.CreateLoggingChannel());
	}
	
	return _consoleLoggingChannel.Get();
}

LoggingChannel* DevLogger::GetViewportLoggingChannel()
{
	if (!_viewportLoggingChannel)
	{
		ViewportLoggingChannelFactory factory;
		_viewportLoggingChannel = TUniquePtr<LoggingChannel>(factory.CreateLoggingChannel());
	}

	return _viewportLoggingChannel.Get();
}
