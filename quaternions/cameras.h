#pragma once

#include "coordinatesystems.h"
#include "projections.h"

class Camera3D {
	CoordinateSystem localCoordinateSystem;
	Vector3D targetPoint;
	ProjectionSurface surface;

public:
	Camera3D();
	Camera3D(Vector3D pos);

	const Vector3D& getPositionGlobal() const;
	const ProjectionSurface& getProjectionSurface() const;
};