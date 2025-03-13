#include <iostream>
#include "vectors.h"
#include "rotations.h"

void test_point_rotation() {
	Vector3D p;        // point to rotate
	Vector3D axis;     // rotation axis
	float angle{ 0 };  // angle of rotation along rotation axis

	// get point coordinates
	std::cout << "coordonnees du point:\n";
	std::cout << "x: ";
	std::cin >> p.x;
	std::cout << "y: ";
	std::cin >> p.y;
	std::cout << "z: ";
	std::cin >> p.z;

	// get rotation axis
	std::cout << "vecteur/axe de rotation:\n";
	std::cout << "x: ";
	std::cin >> axis.x;
	std::cout << "y: ";
	std::cin >> axis.y;
	std::cout << "z: ";
	std::cin >> axis.z;

	// get angle
	std::cout << "angle de rotation (radians): ";
	std::cin >> angle;

	std::cout << "le point " << p << " a pour coordonnees\n";
	rotate_point(p, axis, angle);
	std::cout << p << "\napres une rotation de " << angle << " radians autour du vecteur " << axis << "\n";

}