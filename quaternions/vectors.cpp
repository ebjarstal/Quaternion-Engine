#include "vectors.h"

// Vector3D DEFINITIONS

std::ostream& operator<<(std::ostream& f, const Vector3D& v) {
	// will print Vector3D under format (x, y, z)
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

float Vector3D::getNorm() const {
	return std::sqrt(x * x + y * y + z * z);
}

Vector3D Vector3D::getNormalized() const {
	if (isUnit()) {
		return *this;
	}
	return *this / getNorm();
}

void Vector3D::setNorm(const float& new_norm) {
	x = x * new_norm / getNorm();
	y = y * new_norm / getNorm();
	z = z * new_norm / getNorm();
}

bool Vector3D::isUnit() const {
	return getNorm() == 1.f;
}

float dotProduct(const Vector3D& v1, const Vector3D& v2) {
	// dot product of two the given Vector3D objects.
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector3D crossProduct(const Vector3D& v1, const Vector3D& v2) {
	// cross product of the two given Vector3D objects.
	return {
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x
	};
}

bool areOrthogonal(const Vector3D& v1, const Vector3D& v2) {
	return dotProduct(v1, v2) == 0.f;
}




// Vector4D DEFINITIONS

std::ostream& operator<<(std::ostream& f, const Vector4D& v) {
	// will print Vector4D under format (x, y, z, w)
	f << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
	return f;
}

Vector4D operator+(const Vector4D& v1, const Vector4D& v2) {
	return {
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z,
		v1.w + v2.w
	};
}

Vector4D operator-(const Vector4D& v1, const Vector4D& v2) {
	return {
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z,
		v1.w - v2.w
	};
}

Vector4D operator*(const Vector4D& v, const float& lambda) {
	return {
		lambda * v.x,
		lambda * v.y,
		lambda * v.z,
		lambda * v.w
	};
}

Vector4D operator*(const float& lambda, const Vector4D& v) {
	return v * lambda;
}

Vector4D operator/(const Vector4D& v, const float& lambda) {
	return {
		v.x / lambda,
		v.y / lambda,
		v.z / lambda,
		v.w / lambda
	};
}

float Vector4D::getNorm() const {
	return std::sqrt(x * x + y * y + z * z + w * w);
}

Vector4D Vector4D::getNormalized() const {
	if (isUnit() == true) {
		return *this;
	}
	return *this / getNorm();
}

bool Vector4D::isUnit() const {
	return getNorm() == 1.f;
}

float dotProduct(const Vector4D& v1, const Vector4D& v2) {
	// dot product of two the given Vector4D objects.
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}