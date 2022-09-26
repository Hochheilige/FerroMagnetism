#include "CrystallPunk/Implementation/GrabFeature/GrabberComponent.h"

UGrabberComponent::UGrabberComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGrabberComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (GrabbedComponent)
	{
		FVector StartTraceLocation, EndTraceLocation;
		GetReachLine(StartTraceLocation, EndTraceLocation);

		// move the object that we're holding
		SetTargetLocation(EndTraceLocation);
	}
}

void UGrabberComponent::GetViewLocationAndRotation(FVector& ViewPointLocation_out,
	FRotator& ViewPointRotation_out) const
{
	if (auto const CastedOwner = Cast<APawn>(GetOwner()))
	{
		if (auto const PC = Cast<APlayerController>(CastedOwner->GetController()))
		{
			PC->GetPlayerViewPoint(ViewPointLocation_out, ViewPointRotation_out);
		}
	}
	else
	{
		GetOwner()->GetActorEyesViewPoint(ViewPointLocation_out,
			ViewPointRotation_out);
	}
}

void UGrabberComponent::GetReachLine(FVector& LineStart_out, FVector& LineEnd_out) const
{
	FVector ViewPointLocation;
	FRotator ViewPointRotation;

	GetViewLocationAndRotation(ViewPointLocation, ViewPointRotation);

	LineStart_out = ViewPointLocation;
	LineEnd_out = ViewPointLocation + ViewPointRotation.Vector() * RayLength;
}

FVector UGrabberComponent::GetReachLineStart() const
{
	FVector ViewPointLocation;
	FRotator ViewPointRotation;

	GetViewLocationAndRotation(ViewPointLocation, ViewPointRotation);
	return ViewPointLocation;
}

FVector UGrabberComponent::GetReachLineEnd() const
{
	FVector StartTraceLocation, EndTraceLocation;
	GetReachLine(StartTraceLocation, EndTraceLocation);
	return EndTraceLocation;
}

FHitResult UGrabberComponent::GetItemByRayCast() const
{
	FVector StartTraceLocation, EndTraceLocation;
	GetReachLine(StartTraceLocation, EndTraceLocation);

	FCollisionQueryParams TraceParams(FName("InteractTrace"), bIsComplexTraceEnabled, GetOwner());

	FHitResult HitResult;
	GetWorld()->LineTraceSingleByObjectType(HitResult, StartTraceLocation, EndTraceLocation, FCollisionObjectQueryParams(ECC_PhysicsBody), TraceParams);

	return HitResult;
}

void UGrabberComponent::Grab()
{
	FHitResult const HitResult = GetItemByRayCast();
	if (!HitResult.GetActor())
		return;

	auto const ComponentUnderHit = HitResult.Component.Get();

	GrabComponentAtLocationWithRotation(ComponentUnderHit, NAME_None, ComponentUnderHit->GetOwner()->GetActorLocation(), ComponentUnderHit->GetOwner()->GetActorRotation());
}

void UGrabberComponent::Throw()
{
	FVector OwnerLocation;
	FRotator ForceVector;

	GetViewLocationAndRotation(OwnerLocation, ForceVector);

	GetGrabbedComponent()->AddForce(ForceVector.Vector() * ForceScalar);
}
