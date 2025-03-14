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

public:
	uint8_t r, g, b, a;

public:
	Object();
	Object(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_);
	Object(Vector3D pos);
	Object(Vector3D pos, uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_);

	virtual const std::vector<Vector3D> getPoints() const;

	void rotate(const Vector3D& axis, const float& angle);
	void translate(const Vector3D& v);

	virtual ~Object() = default;
};

class Cube : public Object {
	float size;
	// 8 points by default

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