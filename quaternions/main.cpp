#include "vectors.h"
#include "quaternions.h"
#include "rotations.h"
#include <iostream>
#include <math.h>

int main() {
	Vector3D p   { 0, 2, 2 };
	Vector3D axis{ 0, 1, 0 };  // y axis
	const float angle = 3.14159265358979323846f / 2.f;  // pi / 2

	rotate_point(p, axis, angle);
	std::cout << p << "\n";

	return 0;
}