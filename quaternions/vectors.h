#pragma once

#include <iostream>

struct Vector3D {
	float x, y, z;

public:
	const float getNorm() const;
};

std::ostream& operator<<(std::ostream& f, const Vector3D& v);

Vector3D operator+(const Vector3D& v1, const Vector3D& v2);
Vector3D operator-(const Vector3D& v1, const Vector3D& v2);
Vector3D operator*(const Vector3D& v, const float& lambda);
Vector3D operator*(const float& lambda, const Vector3D& v);
Vector3D operator/(const Vector3D& v, const float& lambda);

float    dotProduct(const Vector3D& v1, const Vector3D& v2);
Vector3D crossProduct(const Vector3D& v1, const Vector3D& v2);