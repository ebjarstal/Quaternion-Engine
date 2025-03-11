#include "quaternions.h"

float Quaternion::getScalar() {
	return scalar;
}

const float Quaternion::getScalar() const {
	return scalar;
}

Vector3D Quaternion::getVector() {
	return vector;
}

const Vector3D Quaternion::getVector() const {
	return vector;
}

bool Quaternion::isZero() const {
	return scalar == 0 && vector.x == 0 && vector.y == 0 && vector.z == 0;
}

bool Quaternion::isIdentity() const {
	return scalar == 1 && vector.x == 0 && vector.y == 0 && vector.z == 0;
}