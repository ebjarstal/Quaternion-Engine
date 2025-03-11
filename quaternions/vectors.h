#pragma once

#include <iostream>

struct Vector3D {
	float x, y, z;
};

std::ostream& operator<<(std::ostream& f, const Vector3D& v);

Vector3D operator+(const Vector3D& v1, const Vector3D& v2);
Vector3D operator-(const Vector3D& v1, const Vector3D& v2);
Vector3D operator*(const Vector3D& v, const float& lambda);
Vector3D operator*(const float& lambda, const Vector3D& v);
Vector3D operator/(const Vector3D& v, const float& lambda);