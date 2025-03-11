#pragma once

#include "vectors.h"
#include <iostream>

class Quaternion {
	float    scalar;	// scalar part (aka real part)
	Vector3D vector;	// vector part (aka imaginary part)

public:
	// constructors
	Quaternion() : scalar(0), vector({ 0 }) {}
	Quaternion(float a, float b, float c, float d) : scalar(a), vector({ b, c, d }) {}
	Quaternion(float a, Vector3D v) : scalar(a), vector(v) {}

	// setters
	void setScalar(const float& a);
	void setVector(const Vector3D& v);
	void setVector(const float& b, const float& c, const float& d);
	void setVectorX(const float& b);
	void setVectorY(const float& c);
	void setVectorZ(const float& d);

	// getters
	const float      getScalar()    const;
	const Vector3D   getVector()    const;
	const Quaternion getConjugate() const;
	const float      getNorm()      const;
	const Quaternion getInverse()   const;
	const Quaternion getVersor()    const;

	// booleans
	bool isZero()     const;
	bool isIdentity() const;
	bool hasInverse() const;
	bool isUnit()     const;
};

std::ostream& operator<<(std::ostream& f, const Quaternion& q);
Quaternion operator+(const Quaternion& q1, const Quaternion& q2);
Quaternion operator-(const Quaternion& q1, const Quaternion& q2);
Quaternion operator*(const Quaternion& q, const float& lambda);
Quaternion operator*(const float& lambda, const Quaternion& q);
Quaternion operator/(const Quaternion& q, const float& lambda);
Quaternion operator*(const Quaternion& q1, const Quaternion& q2);

const float getDistance(const Quaternion& q1, const Quaternion& q2);