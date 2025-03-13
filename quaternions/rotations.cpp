#include "rotations.h"

void rotate_point(Vector3D& point, const Vector3D& axis, const float& angle) {
	Quaternion q{
		std::cos(angle / 2.f),
		axis.getNormalized() * std::sin(angle / 2.f)
	};
	point = (q * point * q.getConjugate()).getVector();
}