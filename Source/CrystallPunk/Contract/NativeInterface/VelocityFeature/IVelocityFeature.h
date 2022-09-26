#pragma once

class IVelocityFeature
{
public:
	IVelocityFeature() = default;

	virtual ~IVelocityFeature() = default;

	virtual FVector GetVelocity() const = 0;

	virtual void Tick(const float deltaSeconds) = 0;
};
