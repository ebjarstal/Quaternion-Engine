#include "tests.h"

#include <iostream>

#include "vectors.h"
#include "rotations.h"
#include "coordinatesystems.h"

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
	rotatePoint(p, axis, angle);
	std::cout << p << "\napres une rotation de " << angle << " radians autour du vecteur " << axis << "\n";

}

void test_coordinate_systems() {
	CoordinateSystem cs1;
	CoordinateSystem cs2({ 10.f, 10.f, -20.f });

	std::cout << "cs1 pos: " << cs1.origin << "\n";
	std::cout << "cs1 frame pos: "
		<< cs1.getFrame().getX() << " "
		<< cs1.getFrame().getY() << " "
		<< cs1.getFrame().getZ() << "\n\n";

	cs1.translate(1.f, -3.4f, -0.4f);

	std::cout << "cs1 after translation\n";
	std::cout << "cs1 pos: " << cs1.origin << "\n";
	std::cout << "cs1 frame pos: "
		<< cs1.getFrame().getX() << " "
		<< cs1.getFrame().getY() << " "
		<< cs1.getFrame().getZ() << "\n\n";

	cs1.rotateAroundOrigin({ 1.f, 1.f, 1.f }, g_PI);

	std::cout << "cs1 after rotation\n";
	std::cout << "cs1 pos: " << cs1.origin << "\n";
	std::cout << "cs1 frame pos: "
		<< cs1.getFrame().getX() << " "
		<< cs1.getFrame().getY() << " "
		<< cs1.getFrame().getZ() << "\n\n";

	cs1.rotateAroundOrigin({ 1, 1, 1 }, g_PI / 3.f);

	std::cout << "cs1 after frame rotation\n";
	std::cout << "cs1 pos: " << cs1.origin << "\n";
	std::cout << "cs1 frame pos: "
		<< cs1.getFrame().getX() << " "
		<< cs1.getFrame().getY() << " "
		<< cs1.getFrame().getZ() << "\n\n";

	std::cout << "cs2 pos: " << cs2.origin << "\n";
	std::cout << "cs2 frame pos: "
		<< cs2.getFrame().getX() << " "
		<< cs2.getFrame().getY() << " "
		<< cs2.getFrame().getZ() << "\n\n";

	cs2.rotateAroundOrigin({ 0, 0, 1.f }, g_PI / 2.f);

	std::cout << "cs2 after rotation\n";
	std::cout << "cs2 pos: " << cs2.origin << "\n";
	std::cout << "cs2 frame pos: "
		<< cs2.getFrame().getX() << " "
		<< cs2.getFrame().getY() << " "
		<< cs2.getFrame().getZ() << "\n\n";

	cs2.translate(4.f, 2.3f, -6.1);

	std::cout << "cs2 after translation\n";
	std::cout << "cs2 pos: " << cs2.origin << "\n";
	std::cout << "cs2 frame pos: "
		<< cs2.getFrame().getX() << " "
		<< cs2.getFrame().getY() << " "
		<< cs2.getFrame().getZ() << "\n\n";

}