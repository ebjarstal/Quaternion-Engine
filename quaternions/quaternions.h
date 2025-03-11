#pragma once

#include <iostream>

struct Vector3D {
	float x, y, z;
};

class Quaternion {
	float    scalar;	// scalar part (real part)
	Vector3D vector;	// vector part (imaginary part)

public:
	Quaternion() : scalar(0), vector({ 0 }) {}
	Quaternion(float a, float b, float c, float d) : scalar(a), vector({ b, c, d }) {}

	// getters
	float          getScalar();
	const float    getScalar() const;
	Vector3D       getVector();
	const Vector3D getVector() const;

	// booleans
	bool isZero()     const;
	bool isIdentity() const;
};

inline std::ostream& operator<<(std::ostream& f, const Quaternion& q) {
	const float    scalar = q.getScalar();
	const Vector3D vector = q.getVector();

	if (q.isZero() == true) {
		f << "0";
		return f;
	}

	if (scalar != 0) f << scalar;
	if (vector.x != 0) {
		if (vector.x > 0) f << "+";
		f << vector.x << "i";
	}
	if (vector.y != 0) {
		if (vector.y > 0) f << "+";
		f << vector.y << "j";
	}
	if (vector.z != 0) {
		if (vector.z > 0) f << "+";
		f << vector.z << "k";
	}

	return f;
}