#include "vectors.h"

std::ostream& operator<<(std::ostream& f, const Vector3D& v) {
	f << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return f;
}

Vector3D operator+(const Vector3D& v1, const Vector3D& v2) {
	return {
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z
	};
}

Vector3D operator-(const Vector3D& v1, const Vector3D& v2) {
	return {
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z
	};
}

Vector3D operator*(const Vector3D& v, const float& lambda) {
	return {
		lambda * v.x,
		lambda * v.y,
		lambda * v.z
	};
}

Vector3D operator*(const float& lambda, const Vector3D& v) {
	return v * lambda;
}

Vector3D operator/(const Vector3D& v, const float& lambda) {
	return {
		v.x / lambda,
		v.y / lambda,
		v.z / lambda
	};
}

const float Vector3D::getNorm() const {
	return std::sqrt(x * x + y * y + z * z);
}

// Returns dot product of two given Vector3D objects.
float dotProduct(const Vector3D& v1, const Vector3D& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Returns cross product of two given Vector3D objects.
Vector3D crossProduct(const Vector3D& v1, const Vector3D& v2) {
	return {
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x
	};
}