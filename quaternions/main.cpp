#include "quaternions.h"
#include <iostream>

int main() {
	Quaternion q1;
	Quaternion q2(0, 0, 0.00f, -13.2f);
	std::cout << q1 << "\n" << q2 << "\n";
	std::cout << q1.isIdentity() << " " << q1.isZero() << "\n";
	return 0;
}