#include "cameras.h"

Camera3D::Camera3D() : localCoordinateSystem(), targetPoint() {

}

Camera3D::Camera3D(Vector3D pos) : localCoordinateSystem(pos), targetPoint() {

}

const Vector3D& Camera3D::getPositionGlobal() const {
	return localCoordinateSystem.origin;
}

const ProjectionSurface& Camera3D::getProjectionSurface() const {
	return surface;
}