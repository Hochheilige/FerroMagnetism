#pragma once

#include "LoggingChannelFactory.h"

/// <summary>
/// Viewport logging channel factory implementation
/// </summary>
class ViewportLoggingChannelFactory final : public LoggingChannelFactory
{
public:
	ViewportLoggingChannelFactory() = default;

	virtual LoggingChannel* CreateLoggingChannel() override;

private:
	static const int MaxMessageCount;

	static const float TimeToDisplay;
};
