#pragma once

#include "LoggingChannelFactory.h"

/// <summary>
/// Console logging channel factory implementation
/// </summary>
class ConsoleLoggingChannelFactory final : public LoggingChannelFactory
{
public:
	ConsoleLoggingChannelFactory() = default;

	virtual LoggingChannel* CreateLoggingChannel() override;
};
