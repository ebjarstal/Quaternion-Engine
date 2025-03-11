#include "vectors.h"
#include "quaternions.h"
#include <iostream>

int main() {
	Quaternion q1(0, 1.f, 0, 0);
	Quaternion q2(0, 0, 1.f, 0);
	std::cout << distanceGeodesic(q1, q2) << "\n";
	return 0;
}