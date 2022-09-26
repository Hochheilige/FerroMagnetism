#include "VelocityFeature.h"

#include "Utils/Assert/AssertUtils.h"

VelocityFeature::VelocityFeature(AActor* owner)
{
	_AssertIsNotNull(owner);
	_ownerPtr = owner;
	_previousLocation = _ownerPtr.IsValid() ? _ownerPtr->GetActorLocation() : FVector::ZeroVector;
}

FVector VelocityFeature::GetVelocity() const
{
	return _velocity;
}

void VelocityFeature::Tick(const float deltaSeconds)
{
	if(!_ownerPtr.IsValid())
	{
		return;
	}

	const auto currentLocation = _ownerPtr->GetActorLocation();
	const auto delta = currentLocation - _previousLocation;
	_previousLocation = currentLocation;
	_velocity = FMath::IsNearlyEqual(deltaSeconds, 0) ? FVector::ZeroVector : delta / deltaSeconds;
}
