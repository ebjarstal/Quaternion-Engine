#pragma once

#include "vectors.h"

class Ray {
	Vector3D origin;
	Vector3D target;

public:
	Ray(Vector3D o, Vector3D t);

	// Sets the ray's origin to the given point.
	void setOrigin(const Vector3D& new_origin);

	// Sets the ray's target to the given point.
	void setTarget(const Vector3D& new_target);

	// Returns the point of origin of the ray.
	const Vector3D& getOrigin() const;

	// Returns the target point of the ray.
	const Vector3D& getTarget() const;

	// Returns the direction vector of the ray.
	Vector3D getDirectionVector() const;

	// Returns the length of the ray.
	// It corresponds to the distance between the origin and the target.
	float getLength() const;
};