#pragma once

#include "CrystallPunk/Implementation/Utils/Log/DevLogger.h"

#define _AssertBlueprintUtilsAssertionFailed \
FString(__FUNCTION__) + FString(" | Line: ") + FStringUtils::ToString(__LINE__) + FString(" | Assertion failed | ")

#define _AssertBlueprintUtilsLogAssertionFailed(message) \
auto assertionFailedMessage = _AssertBlueprintUtilsAssertionFailed + message; \
DevLogger::GetViewportLoggingChannel()->LogError(assertionFailedMessage); \
DevLogger::GetConsoleLoggingChannel()->LogError(assertionFailedMessage); \
