#pragma once

#include "CoreMinimal.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GrabberComponent.generated.h"

UCLASS()
class CRYSTALLPUNK_API UGrabberComponent : public UPhysicsHandleComponent
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	UGrabberComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Config")
		float ForceScalar = 1000000.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Config")
		float RayLength = 100.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Config")
		bool bIsComplexTraceEnabled = true;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void GetViewLocationAndRotation(FVector& ViewPointLocation_out,FRotator& ViewPointRotation_out) const;

	virtual void GetReachLine(FVector& LineStart_out, FVector& LineEnd_out) const;
	FVector GetReachLineStart() const;
	FVector GetReachLineEnd() const;

	FHitResult GetItemByRayCast() const;

	UFUNCTION(BlueprintCallable)
		virtual void Grab();
	UFUNCTION(BlueprintCallable)
		virtual void Throw();
};
