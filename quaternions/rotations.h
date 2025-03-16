#pragma once

#include <vector>

#include "vectors.h"
#include "quaternions.h"

// Rotates the given point along the given axis by the given angle.
Vector3D& rotatePoint(Vector3D& point, const Vector3D& axis, const float& angle);

// Rotates the given points along the given axis by the given angle.
std::vector<Vector3D>& rotatePoints(std::vector<Vector3D>& points, const Vector3D& axis, const float angle);