#include "quaternions.h"

std::ostream& operator<<(std::ostream& f, const Quaternion& q) {
	const float numbers[4]{ q.getScalar(), q.getVector().x, q.getVector().y, q.getVector().z };
	const char  basis_vectors[3]{ 'i', 'j', 'k' };
	for (int i = 0; i < 3; i++) {
		// print absolute value then evaluate sign of next number and print appropriate sign
		f << std::abs(numbers[i]);
		if (i > 0) f << basis_vectors[i - 1];
		if (numbers[i + 1] >= 0.f) f << "+";
		else f << "-";
	}
	f << std::abs(numbers[3]) << basis_vectors[2];
	return f;
}

Quaternion operator+(const Quaternion& q1, const Quaternion& q2) {
	// component-wise addition of the two quaternions.
	return {
		q1.getScalar() + q2.getScalar(),
		q1.getVector() + q2.getVector()
	};
}

Quaternion operator-(const Quaternion& q1, const Quaternion& q2) {
	// component-wise substraction of the two quaternions.
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

Quaternion operator*(const Quaternion& q1, const Quaternion& q2) {
	const float a1 = q1.getScalar();
	const float b1 = q1.getVector().x;
	const float c1 = q1.getVector().y;
	const float d1 = q1.getVector().z;

	const float a2 = q2.getScalar();
	const float b2 = q2.getVector().x;
	const float c2 = q2.getVector().y;
	const float d2 = q2.getVector().z;

	// Hamilton product of two given quaternions
	return {
		a1*a2 - b1*b2 - c1*c2 - d1*d2,
		a1*b2 + b1*a2 + c1*d2 - d1*c2,
		a1*c2 - b1*d2 + c1*a2 + d1*b2,
		a1*d2 + b1*c2 - c1*b2 + d1*a2
	};
}

void Quaternion::setScalar(const float& a) {
	scalar = a;
}

void Quaternion::setVector(const Vector3D& v) {
	vector = v;
}

void Quaternion::setVector(const float& b, const float& c, const float& d) {
	vector = { b, c, d };
}

void Quaternion::setVectorX(const float& b) {
	vector.x = b;
}

void Quaternion::setVectorY(const float& c) {
	vector.y = c;
}

void Quaternion::setVectorZ(const float& d) {
	vector.z = d;
}

const float Quaternion::getScalar() const {
	return scalar;
}

const Vector3D Quaternion::getVector() const {
	return vector;
}

Quaternion Quaternion::getConjugate() const {
	return {
		scalar,
		-1.f * vector
	};
}

float Quaternion::getNorm() const {
	const float a = getScalar();
	const float b = getVector().x;
	const float c = getVector().y;
	const float d = getVector().z;

	return std::sqrt(a * a + b * b + c * c + d * d);
}

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

Quaternion Quaternion::getVersor() const {
	if (isZero() == true) {
		return *this;
	}
	return *this / getNorm();
}

Quaternion* Quaternion::getRoots() const {
	Quaternion roots[2];

	if (isZero() == true) {
		roots[0] = { 0.f, 0.f, 0.f, 0.f };
		roots[1] = { 0.f, 0.f, 0.f, 0.f };
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

bool Quaternion::isZero() const {
	return scalar == 0.f && vector.x == 0.f && vector.y == 0.f && vector.z == 0.f;
}

bool Quaternion::isIdentity() const {
	return scalar == 1.f && vector.x == 0.f && vector.y == 0.f && vector.z == 0.f;
}

bool Quaternion::hasInverse() const {
	return isZero() == false;
}

bool Quaternion::isUnit() const {
	return getNorm() == 1.f;
}

float dotProduct(const Quaternion& q1, const Quaternion& q2) {
	const float a1 = q1.getScalar();
	const float b1 = q1.getVector().x;
	const float c1 = q1.getVector().y;
	const float d1 = q1.getVector().z;

	const float a2 = q2.getScalar();
	const float b2 = q2.getVector().x;
	const float c2 = q2.getVector().y;
	const float d2 = q2.getVector().z;

	return a1 * a2 + b1 * b2 + c1 * c2 + d1 * d2;
}

float distance(const Quaternion& q1, const Quaternion& q2) {
	return (q1 - q2).getNorm();
}

float distanceGeodesic(const Quaternion& q1, const Quaternion& q2) {
	if (q1.isUnit() == false || q2.isUnit() == false) {
		return -1;
	}
	return std::acos(2.f * std::pow((dotProduct(q1, q2)), 2) - 1.f);
}

Quaternion exp(const Quaternion& q) {
	const float a = q.getScalar();
	const Vector3D v = q.getVector();
	const float v_norm = v.getNorm();
	return {
		std::exp(a) * std::cos(v_norm),
		std::exp(a) * v / v_norm * std::sin(v_norm)
	};
}

Quaternion log(const Quaternion& q) {
	const float a = q.getScalar();
	const Vector3D v = q.getVector();
	const float v_norm = v.getNorm();
	return {
		std::log(q.getNorm()),
		v / v_norm * std::acos(a / q.getNorm())
	};
}