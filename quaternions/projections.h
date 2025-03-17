#pragma once

#include "vectors.h"
#include "coordinatesystems.h"
#include "rays.h"

extern const int g_Width;
extern const int g_Height;

// For now we consider the projection surface at the center of the global coordinate system
class ProjectionSurface {
	int width;
	int height;
	// The surface/plane is orthogonal to the Z axis of the local coordinate system.
	// The center of the plane is the same as the origin of the local coordinate system.
	CoordinateSystem localCoordinateSystem;

public:
	ProjectionSurface();
	ProjectionSurface(Vector3D pos);
	ProjectionSurface(int w, int h);
	ProjectionSurface(int w, int h, Vector3D pos);

	Vector2D getIntersectionPoint(const Ray& ray) const;
};