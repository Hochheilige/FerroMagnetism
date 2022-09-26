#pragma once

#include "IVelocityFeature.h"

class IVelocityFeatureFactory
{
public:
	IVelocityFeatureFactory() = default;

	virtual ~IVelocityFeatureFactory() = default;

	virtual IVelocityFeature* Create(AActor* owner) = 0;
};

Expose_TNameOf(IVelocityFeatureFactory)
