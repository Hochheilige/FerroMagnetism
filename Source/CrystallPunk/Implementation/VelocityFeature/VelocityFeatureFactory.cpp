#include "VelocityFeatureFactory.h"

#include "VelocityFeature.h"

IVelocityFeature* VelocityFeatureFactory::Create(AActor* owner)
{
	return new VelocityFeature(owner);
}
