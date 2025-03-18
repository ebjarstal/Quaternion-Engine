#pragma once

#include <vector>
#include "vectors.h"
#include "rotations.h"
#include "coordinatesystems.h"

// The mother class of all 3D objects meant to be drawn in the Quaternion engine.
class Object {
protected:
	CoordinateSystem localCoordinateSystem;
	std::vector<Vector3D> points;

public:
	uint8_t r, g, b, a;

public:
	Object();
	Object(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_);
	Object(Vector3D pos);
	Object(Vector3D pos, uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_);

	// Returns the object's calculated centroid.
	Vector3D getCentroid() const;

	// Returns a vector of all the object's points with their local coordinates.
	const std::vector<Vector3D> getPointsLocal()  const;

	// Returns a vector of all the object's points with their global coordinates.
	std::vector<Vector3D> getPointsGlobal() const;

	// Returns the object's local coordinate system.
	const CoordinateSystem& getCoordinateSystem() const;

	// Changes the object's color to the given RGBA values.
	void setColor(const uint8_t new_r, const uint8_t new_g, const uint8_t new_b, const uint8_t new_a);

	// Rotates all the object's points by a given angle around a given axis.
	// Note that the axis' origin is located at the center of the object's local coordinate system.
	void rotateAroundCenter(const Vector3D& axis, const float& angle);

	// Translates the object by a given displacement.
	void translate(const Vector3D& dv);

	// Translates the object by a given displacement.
	void translate(const float& dx, const float& dy, const float& dz);

	// Moves the center of the object to the given position.
	void moveTo(const Vector3D& pos);

	// Moves the center of the object to the given position.
	void moveTo(const float& dx, const float& dy, const float& dz);

	virtual ~Object() = default;

protected:
	// This method is used to generate the object's points within the constructor.
	virtual void generatePointsLocal() = 0;
};

// Made this class just for testing purposes
class Cube : public Object {
	float size;
	
	// Initializes all the Cube's points in an ordered way so that all its edges can
	// be rendered in a for loop with two points per iteration
	void generatePointsLocal();

public:
	Cube();
	Cube(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_);
	Cube(Vector3D pos);
	Cube(Vector3D pos, uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_);
	Cube(float s);
	Cube(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_, float s);
	Cube(Vector3D pos, uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_, float s);

	const float& getSize() const;

	void setSize(const float& new_size);
};

class Pyramid : public Object {
	float base_size;
	float height;

	void generatePointsLocal();

public:
	Pyramid();
};