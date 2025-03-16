#pragma once

#include "vectors.h"
#include "quaternions.h"
#include "rotations.h"

class OrthonormalFrame {
	Vector3D frame_vectors[3];

public:
	OrthonormalFrame();

	// Returns the X axis of the frame.
	const Vector3D& getX() const;

	// Returns the Y axis of the frame.
	const Vector3D& getY() const;

	// Returns the Z axis of the frame.
	const Vector3D& getZ() const;

	// Rotates the frame by a given angle along a given axis.
	void rotate(const Vector3D& axis, const float& angle);
};

class CoordinateSystem {
	// The local orthonormal frame of the coordinate system.
	OrthonormalFrame frame;

public:
	// The point of origin of the frame with global coordinates.
	Vector3D origin;

public:
	CoordinateSystem();
	CoordinateSystem(Vector3D pos);

	// Returns the local orthonormal frame of the coordinate system.
	const OrthonormalFrame& getFrame() const;

	// Translates the object by a given displacement.
	void translate(const float& dx, const float& dy, const float& dz);

	// Translates the object by a given displacement.
	void translate(const Vector3D& dv);

	// Moves the origin of the coordinate system to the given position.
	void moveTo(const Vector3D& pos);

	// Moves the origin of the coordinate system to the given position.
	void moveTo(const float& dx, const float& dy, const float& dz);

	// Rotates the coordinate system's frame around its origin by a given angle along a given axis.
	void rotateAroundOrigin(const Vector3D& axis, const float& angle);
};