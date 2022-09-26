#include "NumericLimitsBlueprintUtils.h"

int UNumericLimitsBlueprintUtils::GetMaxInt(AActor* actor)
{
	return TNumericLimits<int>::Max();
}

int UNumericLimitsBlueprintUtils::GetLowestInt(AActor* actor)
{
	return TNumericLimits<int>::Lowest();
}

float UNumericLimitsBlueprintUtils::GetMaxFloat(AActor* actor)
{
	return TNumericLimits<float>::Max();
}

float UNumericLimitsBlueprintUtils::GetLowestFloat(AActor* actor)
{
	return TNumericLimits<float>::Lowest();
}

float UNumericLimitsBlueprintUtils::GetWorldMax()
{
	return WORLD_MAX;
}

float UNumericLimitsBlueprintUtils::GetHalfWorldMax()
{
	return HALF_WORLD_MAX;
}
