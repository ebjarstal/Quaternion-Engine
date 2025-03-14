#pragma once

#include "vectors.h"
#include "quaternions.h"
#include "rotations.h"

class OrthonormalFrame {
	Vector3D frame_vectors[3];

public:
	OrthonormalFrame();

	const Vector3D& getX();
	const Vector3D& getY();
	const Vector3D& getZ();

	void rotate(const Vector3D& axis, const float& angle);
};

class CoordinateSystem {
	OrthonormalFrame frame;

public:
	Vector3D globalPosition;

public:
	CoordinateSystem();
	CoordinateSystem(Vector3D pos);

	const Vector3D& getGlobalPosition() const;
	OrthonormalFrame& getFrame();

	void translate(const float& dx, const float& dy, const float& dz);
	void rotate(const Vector3D& axis, const float& angle);
};