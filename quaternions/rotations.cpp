#include "rotations.h"

Vector3D& rotatePoint(Vector3D& point, const Vector3D& axis, const float& angle) {
	Quaternion q{
		std::cos(angle / 2.f),
		axis.getNormalized() * std::sin(angle / 2.f)
	};
	point = (q * point * q.getConjugate()).getVector();
	return point;
}

std::vector<Vector3D>& rotatePoints(std::vector<Vector3D>& points, const Vector3D& axis, const float angle) {
	Quaternion q{
		std::cos(angle / 2.f),
		axis.getNormalized() * std::sin(angle / 2.f)
	};
	for (Vector3D& point : points) {
		point = (q * point * q.getConjugate()).getVector();
	}
	return points;
}