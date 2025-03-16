#include "objects.h"

// OBJECT METHODS

Object::Object()
	: localCoordinateSystem(), points(), r(0xFF), g(0xFF), b(0xFF), a(0xFF) {}

Object::Object(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_) :
	localCoordinateSystem(), points(), r(r_), g(g_), b(b_), a(a_) {}

Object::Object(Vector3D pos) :
	localCoordinateSystem(pos), points(), r(0xFF), g(0xFF), b(0xFF), a(0xFF) {}

Object::Object(Vector3D pos, uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_) :
	localCoordinateSystem(pos), points(), r(r_), g(g_), b(b_), a(a_) {}

const Vector3D& Object::getCenter() const {
	return localCoordinateSystem.origin;
}

const std::vector<Vector3D> Object::getPointsLocal() const {
	return points;
}

const std::vector<Vector3D> Object::getPointsGlobal() const {
	std::vector<Vector3D> points_global;
	for (const Vector3D& point : points) {
		points_global.push_back(point + getCenter());
	}
	return points_global;
}

const CoordinateSystem& Object::getCoordinateSystem() const {
	return localCoordinateSystem;
};

void Object::rotateAroundCenter(const Vector3D& axis, const float& angle) {
	localCoordinateSystem.rotateAroundOrigin(axis, angle);
	for (Vector3D& point : points) {
		rotatePoint(point, axis, angle);
	}
}

void Object::translate(const Vector3D& dv) {
	localCoordinateSystem.translate(dv);
}







// CUBE METHODS

Cube::Cube() : Object(), size(0.f) {
	generateLocalPoints();
}

Cube::Cube(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_) : Object(r_, g_, b_, a_), size(0.f) {

	generateLocalPoints();
}

Cube::Cube(Vector3D pos) : Object(pos), size(0.f) {
	generateLocalPoints();
}

Cube::Cube(Vector3D pos, uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_) : Object(pos, r_, g_, b_, a_), size(0.f) {
	generateLocalPoints();
}

Cube::Cube(float s) : Object(), size(s) {
	generateLocalPoints();
}

Cube::Cube(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_, float s) : Object(r_, g_, b_, a_), size(s) {
	generateLocalPoints();
}

Cube::Cube(Vector3D pos, uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_, float s) : Object(pos, r_, g_, b_, a_), size(s) {
	generateLocalPoints();
}

void Cube::generateLocalPoints() {
	points.clear();

	points.push_back({ -size / 2.f, -size / 2.f, -size / 2.f });
	points.push_back({ -size / 2.f, -size / 2.f,  size / 2.f });
	points.push_back({ size / 2.f, -size / 2.f,  size / 2.f });
	points.push_back({ size / 2.f, -size / 2.f, -size / 2.f });
	points.push_back({ -size / 2.f, -size / 2.f, -size / 2.f });
	points.push_back({ -size / 2.f,  size / 2.f, -size / 2.f });
	points.push_back({ -size / 2.f,  size / 2.f,  size / 2.f });
	points.push_back({ -size / 2.f, -size / 2.f,  size / 2.f });
	points.push_back({ -size / 2.f,  size / 2.f,  size / 2.f });
	points.push_back({ size / 2.f,  size / 2.f,  size / 2.f });
	points.push_back({ size / 2.f, -size / 2.f,  size / 2.f });
	points.push_back({ size / 2.f,  size / 2.f,  size / 2.f });
	points.push_back({ size / 2.f,  size / 2.f, -size / 2.f });
	points.push_back({ size / 2.f, -size / 2.f, -size / 2.f });
	points.push_back({ size / 2.f,  size / 2.f, -size / 2.f });
	points.push_back({ -size / 2.f,  size / 2.f, -size / 2.f });

}
