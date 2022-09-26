#include "LogBlueprintUtils.h"

#include "CrystallPunk/Implementation/Utils/Log/DevLogger.h"

void ULogBlueprintUtils::Log(const FString& string)
{
	DevLogger::GetViewportLoggingChannel()->Log(string);
}

void ULogBlueprintUtils::LogWarning(const FString& string)
{
	DevLogger::GetViewportLoggingChannel()->LogWarning(string);
}

void ULogBlueprintUtils::LogError(const FString& string)
{
	DevLogger::GetViewportLoggingChannel()->LogError(string);
}
