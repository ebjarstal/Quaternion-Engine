#include "quaternions.h"

std::ostream& operator<<(std::ostream& f, const Quaternion& q) {
	const float numbers[4]{ q.getScalar(), q.getVector().x, q.getVector().y, q.getVector().z };
	const char  basis_vectors[3]{ 'i', 'j', 'k' };
	for (int i = 0; i < 3; i++) {
		// print absolute value then evaluate sign of next number and print appropriate sign
		f << std::abs(numbers[i]);
		if (i > 0) f << basis_vectors[i - 1];
		if (numbers[i + 1] >= 0) f << "+";
		else f << "-";
	}
	f << std::abs(numbers[3]) << basis_vectors[2];
	return f;
}

// Returns result of component-wise addition of two quaternions.
Quaternion operator+(const Quaternion& q1, const Quaternion& q2) {
	return {
		q1.getScalar() + q2.getScalar(),
		q1.getVector() + q2.getVector()
	};
}

// Returns result of component-wise substraction of two quaternions.
Quaternion operator-(const Quaternion& q1, const Quaternion& q2) {
	return {
		q1.getScalar() - q2.getScalar(),
		q1.getVector() - q2.getVector()
	};
}

Quaternion operator*(const Quaternion& q, const float& lambda) {
	return {
		lambda * q.getScalar(),
		lambda * q.getVector()
	};
}

Quaternion operator*(const float& lambda, const Quaternion& q) {
	return q * lambda;
}

Quaternion operator/(const Quaternion& q, const float& lambda) {
	return {
		q.getScalar() / lambda,
		q.getVector() / lambda
	};
}

// Returns Hamilton product of two given quaternions
Quaternion operator*(const Quaternion& q1, const Quaternion& q2) {
	const float a1 = q1.getScalar();
	const float b1 = q1.getVector().x;
	const float c1 = q1.getVector().y;
	const float d1 = q1.getVector().z;
	const float a2 = q2.getScalar();
	const float b2 = q2.getVector().x;
	const float c2 = q2.getVector().y;
	const float d2 = q2.getVector().z;

	return {
		a1*a2 - b1*b2 - c1*c2 - d1*d2,
		a1*b2 + b1*a2 + c1*d2 - d1*c2,
		a1*c2 - b1*d2 + c1*a2 + d1*b2,
		a1*d2 + b1*c2 - c1*b2 + d1*a2
	};
}

// Sets the given argument as the quaternion's scalar.
void Quaternion::setScalar(const float& a) {
	scalar = a;
}

// Sets the given Vector3D argument as the quaternion's vector.
void Quaternion::setVector(const Vector3D& v) {
	vector = v;
}

// Forms a Vector3D object from the given arguments and sets it as the quaternion's vector.
void Quaternion::setVector(const float& b, const float& c, const float& d) {
	vector = { b, c, d };
}

// Sets the given argument as the first element of the quaternion's vector.
void Quaternion::setVectorX(const float& b) {
	vector.x = b;
}

// Sets the given argument as the second element of the quaternion's vector.
void Quaternion::setVectorY(const float& c) {
	vector.y = c;
}

// Sets the given argument as the third element of the quaternion's vector.
void Quaternion::setVectorZ(const float& d) {
	vector.z = d;
}

// Returns (float) real part of Quaternion object.
const float Quaternion::getScalar() const {
	return scalar;
}

// Returns (Vector3D) vector part of Quaternion object.
// See definition of Vector3D struct for more information.
const Vector3D Quaternion::getVector() const {
	return vector;
}

// Returns (Quaternion) conjugate of Quaternion object.
Quaternion Quaternion::getConjugate() const {
	return {
		scalar,
		-1 * vector
	};
}

// Returns the norm of the quaternion.
// By definition, it is equal to the square root of the product of the quaternion and its conjugate.
float Quaternion::getNorm() const {
	const float a = getScalar();
	const float b = getVector().x;
	const float c = getVector().y;
	const float d = getVector().z;

	return std::sqrt(a * a + b * b + c * c + d * d);
}

// If the quaternion is nonzero, returns the quaternion's inverse.
// Note that if the quaternion is zero, the method will simply return of a copy of the quaternion.
// This is because the inverse of a zero quaternion is undefined.
Quaternion Quaternion::getInverse() const {
	if (isZero() == false) {
		return *this;
	}

	const float a = getScalar();
	const float b = getVector().x;
	const float c = getVector().y;
	const float d = getVector().z;

	return getConjugate() / (a * a + b * b + c * c + d * d);
}

// Returns the versor of the quaternion.
// By definition, the versor of a quaternion is the division of itself by its norm
// Note that it results in a unit quaternion.
// Note also that if the quaterion is zero, the method will simply return a copy of the quaternion.
// This is because the versor of a zero quaternion is undefined.
Quaternion Quaternion::getVersor() const {
	if (isZero() == true) {
		return *this;
	}
	return *this / getNorm();
}

// Returns the roots of the quaternion. If the quaternion is zero, the two roots are zero.
// Note that if the quaternion is non-zero, the first root is 'negative' and the second is 'positive'.
Quaternion* Quaternion::getRoots() const {
	Quaternion roots[2];

	if (isZero() == true) {
		roots[0] = { 0, 0, 0, 0 };
		roots[1] = { 0, 0, 0, 0 };
		return roots;
	}
	// 'negative' root
	roots[0] = {
		-1.f * std::sqrt(1.f/2.f*(getNorm() + scalar)),
		-1.f * vector / vector.getNorm() * std::sqrt(1.f/2.f*(getNorm() - scalar))
	};
	// 'positive' root
	roots[1] = {
		std::sqrt(1.f / 2.f * (scalar + getNorm())),
		vector / vector.getNorm() * std::sqrt(1.f / 2.f * (getNorm() - scalar))
	};

	return roots;
}

// Returns true if real and vector parts are null. Returns false otherwise.
bool Quaternion::isZero() const {
	return scalar == 0 && vector.x == 0 && vector.y == 0 && vector.z == 0;
}

// Returns true if real part is equal to 1 and vector part is null. Returns false otherwise.
bool Quaternion::isIdentity() const {
	return scalar == 1 && vector.x == 0 && vector.y == 0 && vector.z == 0;
}

// Returns true if the quaternion is not the zero quaternion. Returns false otherwise.
bool Quaternion::hasInverse() const {
	return isZero() == false;
}

// Returns true if the quaternion is of norm one. Returns false otherwise.
bool Quaternion::isUnit() const {
	return getNorm() == 1;
}

// Returns the distance between the two given quaternions.
// Note that this value is defined as the norm of their difference.
float getDistance(const Quaternion& q1, const Quaternion& q2) {
	return (q1 - q2).getNorm();
}