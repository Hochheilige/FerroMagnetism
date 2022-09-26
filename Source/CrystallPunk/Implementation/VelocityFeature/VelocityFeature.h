#pragma once

#include "CrystallPunk/Contract/NativeInterface/VelocityFeature/IVelocityFeature.h"

class VelocityFeature final : public IVelocityFeature
{
public:
	VelocityFeature(AActor* owner);

	virtual FVector GetVelocity() const override;

	virtual void Tick(const float deltaSeconds) override;

private:
	TWeakObjectPtr<AActor> _ownerPtr = nullptr;

	FVector _previousLocation = FVector::ZeroVector;

	FVector _velocity = FVector::ZeroVector;
};
