#include "quaternions.h"
#include <iostream>

int main() {
	// Initialization test
	Quaternion q1;
	Quaternion q2(0, 2, 3, 4);
	Quaternion q3(2, { -4, -3, -1 });

	// Boolean test
	std::cout << q1.isZero() << " " << q1.isIdentity() << "\n";
	// operator<< test
	std::cout << q2 << "\n";
	// Addition test
	std::cout << q2 + q3 << "\n";
	// Scalar multiplication test
	std::cout << 2.5 * q2 - 3 * q3 << "\n";
	// Conjugate test
	std::cout << q3.getConjugate().getConjugate() << "\n";
	// Hamilton product test
	std::cout << (q2 * q3).getConjugate() << "\n";
	std::cout << q3.getConjugate() * q2.getConjugate() << "\n";
	// Norm test
	std::cout << (3 * q3).getNorm() << "\n";
	std::cout << 3 * q3.getNorm() << "\n";
	// Distance test
	std::cout << getDistance(q2, q3) << "\n";
	std::cout << getDistance(q3, q2) << "\n";
	return 0;
}