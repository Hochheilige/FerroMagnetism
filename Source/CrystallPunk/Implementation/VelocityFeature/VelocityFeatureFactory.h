#pragma once

#include "CrystallPunk/Contract/NativeInterface/VelocityFeature/IVelocityFeatureFactory.h"

class VelocityFeatureFactory final : public IVelocityFeatureFactory
{
public:
	VelocityFeatureFactory() = default;

	virtual IVelocityFeature* Create(AActor* owner) override;
};
