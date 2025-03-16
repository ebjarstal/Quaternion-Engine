#pragma once

#include "vectors.h"
#include "coordinatesystems.h"
#include "rays.h"

extern const int g_Width;
extern const int g_Height;

class ProjectionSurface {
	int width;
	int height;
	CoordinateSystem localCoordinateSystem;

public:
	ProjectionSurface();
	ProjectionSurface(Vector3D pos);
	ProjectionSurface(int w, int h);
	ProjectionSurface(int w, int h, Vector3D pos);

	Vector2D getIntersectionPoint(const Ray& ray) const;
};