#include "cameras.h"

Camera3D::Camera3D() : localCoordinateSystem(), targetPoint() {

}

Camera3D::Camera3D(Vector3D pos) : localCoordinateSystem(pos), targetPoint() {

}