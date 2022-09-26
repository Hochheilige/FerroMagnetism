#include "ViewportLoggingChannelFactory.h"
#include "ViewportLoggingChannel.h"

const int ViewportLoggingChannelFactory::MaxMessageCount = -1;

const float ViewportLoggingChannelFactory::TimeToDisplay = 10.0f;

LoggingChannel* ViewportLoggingChannelFactory::CreateLoggingChannel()
{
	return new ViewportLoggingChannel(CyberBeachVolleyballLog.GetCategoryName(), MaxMessageCount, TimeToDisplay);
}
