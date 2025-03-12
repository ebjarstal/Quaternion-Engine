#include "rotations.h"

void rotate_point(Vector3D& point, const Vector3D& axis, const float& angle) {
	Vector3D normalized_axis{ axis.getNormalized() };
	Quaternion p_prime{ point };
	Quaternion q{
		std::cos(angle / 2.f),
		normalized_axis * std::sin(angle / 2.f)
	};
	point = (q * p_prime * q.getConjugate()).getVector();
}