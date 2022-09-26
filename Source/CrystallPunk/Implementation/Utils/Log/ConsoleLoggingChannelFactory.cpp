#include "ConsoleLoggingChannelFactory.h"
#include "ConsoleLoggingChannel.h"

LoggingChannel* ConsoleLoggingChannelFactory::CreateLoggingChannel()
{
	return new ConsoleLoggingChannel(CyberBeachVolleyballLog.GetCategoryName());
}
