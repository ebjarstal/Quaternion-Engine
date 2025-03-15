#pragma once

#include <vector>
#include "vectors.h"
#include "rotations.h"
#include "coordinatesystems.h"

// Abstract Object class
class Object {
protected:
	CoordinateSystem localCoordinateSystem;
	std::vector<Vector3D> points;
	virtual void initPoints() = 0;

public:
	uint8_t r, g, b, a;

public:
	Object();
	Object(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_);
	Object(Vector3D pos);
	Object(Vector3D pos, uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_);

	virtual const std::vector<Vector3D> getPoints() const;
	const CoordinateSystem& getCoordinateSystem() const;

	void rotate(const Vector3D& axis, const float& angle);
	void translate(const Vector3D& v);

	virtual ~Object() = default;
};

class Cube : public Object {
	float size;
	
	// Initializes all the Cube's points in an ordered way so that all its edges can
	// be rendered in a for loop with two points per iteration
	void initPoints();

public:
	Cube();
	Cube(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_);
	Cube(Vector3D pos);
	Cube(Vector3D pos, uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_);
	Cube(float s);
	Cube(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_, float s);
	Cube(Vector3D pos, uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_, float s);

	const std::vector<Vector3D> getPoints() const override;
};