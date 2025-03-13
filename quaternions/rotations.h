#pragma once

#include "vectors.h"
#include "quaternions.h"

// Rotates the given point along the given axis by the given angle.
void rotatePoint(Vector3D& point, const Vector3D& axis, const float& angle);