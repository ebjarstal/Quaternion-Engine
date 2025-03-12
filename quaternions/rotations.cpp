#include "rotations.h"

void rotate_point(Vector3D& point, const Vector3D& axis, const float& angle) {
	Quaternion p_prime{ point };
	Quaternion q{
		std::cos(angle / 2.f),
		axis* std::sin(angle / 2.f)
	};
	point = (q * p_prime * q.getConjugate()).getVector();
}