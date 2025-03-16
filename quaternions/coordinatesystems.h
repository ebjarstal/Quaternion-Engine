#pragma once

#include "vectors.h"
#include "quaternions.h"
#include "rotations.h"

class OrthonormalFrame {
	Vector3D frame_vectors[3];

public:
	OrthonormalFrame();

	const Vector3D& getX() const;
	const Vector3D& getY() const;
	const Vector3D& getZ() const;

	void rotate(const Vector3D& axis, const float& angle);
};

class CoordinateSystem {
	OrthonormalFrame frame;

public:
	// global position
	Vector3D origin;

public:
	CoordinateSystem();
	CoordinateSystem(Vector3D pos);

	OrthonormalFrame& getFrame();

	void translate(const float& dx, const float& dy, const float& dz);
	void translate(const Vector3D& dv);
	void rotateAroundOrigin(const Vector3D& axis, const float& angle);
};