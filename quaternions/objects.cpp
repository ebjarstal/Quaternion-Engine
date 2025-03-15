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

const std::vector<Vector3D> Object::getPoints() const {
	return points;
}

const CoordinateSystem& Object::getCoordinateSystem() const {
	return localCoordinateSystem;
};

void Object::rotate(const Vector3D& axis, const float& angle) {
	for (Vector3D& point : points) {
		rotatePoint(point, axis, angle);
	}
}

void Object::translate(const Vector3D& v) {
	localCoordinateSystem.globalPosition = localCoordinateSystem.globalPosition + v;
	for (Vector3D& point : points) {
		point = point + v;
	}
}







// CUBE METHODS

Cube::Cube() : Object(), size(0.f) {
	initPoints();
}

Cube::Cube(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_) : Object(r_, g_, b_, a_), size(0.f) {

	initPoints();
}

Cube::Cube(Vector3D pos) : Object(pos), size(0.f) {
	initPoints();
}

Cube::Cube(Vector3D pos, uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_) : Object(pos, r_, g_, b_, a_), size(0.f) {
	initPoints();
}

Cube::Cube(float s) : Object(), size(s) {
	initPoints();
}

Cube::Cube(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_, float s) : Object(r_, g_, b_, a_), size(s) {
	initPoints();
}

Cube::Cube(Vector3D pos, uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_, float s) : Object(pos, r_, g_, b_, a_), size(s) {
	initPoints();
}

void Cube::initPoints() {
	Vector3D center_pos = localCoordinateSystem.globalPosition;

	points.push_back({ center_pos.x - size / 2.f, center_pos.y - size / 2.f, center_pos.z - size / 2.f });
	points.push_back({ center_pos.x - size / 2.f, center_pos.y - size / 2.f, center_pos.z + size / 2.f });
	points.push_back({ center_pos.x + size / 2.f, center_pos.y - size / 2.f, center_pos.z + size / 2.f });
	points.push_back({ center_pos.x + size / 2.f, center_pos.y - size / 2.f, center_pos.z - size / 2.f });
	points.push_back({ center_pos.x - size / 2.f, center_pos.y - size / 2.f, center_pos.z - size / 2.f });
	points.push_back({ center_pos.x - size / 2.f, center_pos.y + size / 2.f, center_pos.z - size / 2.f });
	points.push_back({ center_pos.x - size / 2.f, center_pos.y + size / 2.f, center_pos.z + size / 2.f });
	points.push_back({ center_pos.x - size / 2.f, center_pos.y - size / 2.f, center_pos.z + size / 2.f });
	points.push_back({ center_pos.x - size / 2.f, center_pos.y + size / 2.f, center_pos.z + size / 2.f });
	points.push_back({ center_pos.x + size / 2.f, center_pos.y + size / 2.f, center_pos.z + size / 2.f });
	points.push_back({ center_pos.x + size / 2.f, center_pos.y - size / 2.f, center_pos.z + size / 2.f });
	points.push_back({ center_pos.x + size / 2.f, center_pos.y + size / 2.f, center_pos.z + size / 2.f });
	points.push_back({ center_pos.x + size / 2.f, center_pos.y + size / 2.f, center_pos.z - size / 2.f });
	points.push_back({ center_pos.x + size / 2.f, center_pos.y - size / 2.f, center_pos.z - size / 2.f });
	points.push_back({ center_pos.x + size / 2.f, center_pos.y + size / 2.f, center_pos.z - size / 2.f });
	points.push_back({ center_pos.x - size / 2.f, center_pos.y + size / 2.f, center_pos.z - size / 2.f });
}

const std::vector<Vector3D> Cube::getPoints() const {
	return points;
}