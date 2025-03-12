#pragma once

#include "vectors.h"
#include <iostream>

class Quaternion {
	float    scalar;	// scalar part (aka real part)
	Vector3D vector;	// vector part (aka imaginary part)

public:
	// Constructor for the zero quaternion.
	Quaternion() : scalar(0), vector({ 0 }) {}
	// Constructor for a quaternion.
	Quaternion(float a, float b, float c, float d) : scalar(a), vector({ b, c, d }) {}
	// Constructor for a quaternion.
	Quaternion(float a, Vector3D v) : scalar(a), vector(v) {}
	// Constructor for real quaternions.
	Quaternion(float a) : scalar(a), vector({0}) {}
	// Constructor for pure imaginary quaternions.
	Quaternion (Vector3D v) : scalar(0), vector(v) {}

	// Sets the given argument as the quaternion's scalar.
	void setScalar(const float& a);

	// Sets the given Vector3D argument as the quaternion's vector.
	void setVector(const Vector3D& v);

	// Forms a Vector3D object from the given arguments and sets it as the quaternion's vector.
	void setVector(const float& b, const float& c, const float& d);

	// Sets the given argument as the first element of the quaternion's vector.
	void setVectorX(const float& b);

	// Sets the given argument as the second element of the quaternion's vector.
	void setVectorY(const float& c);

	// Sets the given argument as the third element of the quaternion's vector.
	void setVectorZ(const float& d);

	// Returns (float) real part of Quaternion object.
	const float getScalar() const;

	// Returns (Vector3D) vector part of Quaternion object.
	// See definition of Vector3D struct for more information.
	const Vector3D getVector() const;

	// Returns (Quaternion) conjugate of Quaternion object.
	Quaternion getConjugate() const;

	// Returns the norm of the quaternion.
	float getNorm() const;

	// If the quaternion is nonzero, returns the quaternion's inverse.
	// Note that if the quaternion is zero, the method will simply return of a copy of the quaternion.
	// This is because the inverse of a zero quaternion is undefined.
	Quaternion getInverse() const;

	// Returns the versor of the quaternion.
	// Note that it results in a unit quaternion.
	// Note also that if the quaterion is zero, the method will simply return a copy of the quaternion.
	// This is because the versor of a zero quaternion is undefined.
	Quaternion getVersor() const;

	// Returns the roots of the quaternion. If the quaternion is zero, the two roots are zero.
	// Note that if the quaternion is non-zero, the first root is 'negative' and the second is 'positive'.
	Quaternion* getRoots() const;

	// Returns true if real and vector parts are null. Returns false otherwise.
	bool isZero() const;

	// Returns true if real part is equal to 1 and vector part is null. Returns false otherwise.
	bool isIdentity() const;

	// Returns true if the quaternion is not the zero quaternion. Returns false otherwise.
	bool hasInverse() const;

	// Returns true if the quaternion is of norm one. Returns false otherwise.
	bool isUnit()     const;
};

std::ostream& operator<<(std::ostream& f, const Quaternion& q);
Quaternion operator+(const Quaternion& q1, const Quaternion& q2);
Quaternion operator-(const Quaternion& q1, const Quaternion& q2);
Quaternion operator*(const Quaternion& q, const float& lambda);
Quaternion operator*(const float& lambda, const Quaternion& q);
Quaternion operator/(const Quaternion& q, const float& lambda);
Quaternion operator*(const Quaternion& q1, const Quaternion& q2);

// Retuns the dot product of two given quaternions.
float dotProduct(const Quaternion& q1, const Quaternion& q2);

// Returns the distance between the two given quaternions.
// Note that this value is defined as the norm of their difference.
float distance(const Quaternion& q1, const Quaternion& q2);

// Returns the geodesic distance between the two given quaternions if they are unit quaternions.
// Note that if the two given quaternions are not unit quaternions, the return value will be -1.
float distanceGeodesic(const Quaternion& q1, const Quaternion& q2);

// Returns the exponential of the given quaternion.
Quaternion exp(const Quaternion& q);

// Returns the natural logarithm of the given quaternion.
Quaternion log(const Quaternion& q);