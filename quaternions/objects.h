#pragma once

#include <vector>
#include "vectors.h"
#include "rotations.h"
#include "coordinatesystems.h"

// Abstract Object class
class Object {
protected:
	// From the perspective of the object, the coordinates of its points are relative to its center
	// Therefore when the object gets rotated, the axis of rotation's origin is the object's center
	CoordinateSystem localCoordinateSystem;
	std::vector<Vector3D> points;

public:
	uint8_t r, g, b, a;

public:
	Object();
	Object(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_);
	Object(Vector3D pos);
	Object(Vector3D pos, uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_);

	Vector3D getCentroid() const;

	const std::vector<Vector3D> getPointsLocal()  const;
	      std::vector<Vector3D> getPointsGlobal() const;

	const CoordinateSystem& getCoordinateSystem() const;

	void rotateAroundCenter(const Vector3D& axis, const float& angle);

	void translate(const Vector3D& dv);
	void translate(const float& dx, const float& dy, const float& dz);

	void moveTo(const Vector3D& pos);
	void moveTo(const float& dx, const float& dy, const float& dz);

	virtual ~Object() = default;

protected:
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