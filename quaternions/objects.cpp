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

Vector3D Object::getCentroid() const {
	Vector3D center = { 0, 0, 0 };
	for (const Vector3D& point : points) {
		center = center + point;
	}
	return center / points.size();
}

const std::vector<Vector3D> Object::getPointsLocal() const {
	return points;
}

std::vector<Vector3D> Object::getPointsGlobal() const {
	std::vector<Vector3D> points_global;
	for (const Vector3D& point : points) {
		points_global.push_back(point + localCoordinateSystem.origin);
	}
	return points_global;
}

const CoordinateSystem& Object::getCoordinateSystem() const {
	return localCoordinateSystem;
};

void Object::setColor(const uint8_t new_r, const uint8_t new_g, const uint8_t new_b, const uint8_t new_a) {
	r = new_r;
	g = new_g;
	b = new_b;
	a = new_a;
}

void Object::rotateAroundCenter(const Vector3D& axis, const float& angle) {
	localCoordinateSystem.rotateAroundOrigin(axis, angle);
	rotatePoints(points, axis, angle);
}

void Object::translate(const Vector3D& dv) {
	localCoordinateSystem.translate(dv);
}

void Object::translate(const float& dx, const float& dy, const float& dz) {
	localCoordinateSystem.translate(dx, dy, dz);
}

void Object::moveTo(const Vector3D& pos) {
	localCoordinateSystem.moveTo(pos);
}

void Object::moveTo(const float& dx, const float& dy, const float& dz) {
	localCoordinateSystem.moveTo(dx, dy, dz);
}







// CUBE METHODS

Cube::Cube() : Object(), size(0.f) {
	generatePointsLocal();
}

Cube::Cube(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_) : Object(r_, g_, b_, a_), size(0.f) {

	generatePointsLocal();
}

Cube::Cube(Vector3D pos) : Object(pos), size(0.f) {
	generatePointsLocal();
}

Cube::Cube(Vector3D pos, uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_) : Object(pos, r_, g_, b_, a_), size(0.f) {
	generatePointsLocal();
}

Cube::Cube(float s) : Object(), size(s) {
	generatePointsLocal();
}

Cube::Cube(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_, float s) : Object(r_, g_, b_, a_), size(s) {
	generatePointsLocal();
}

Cube::Cube(Vector3D pos, uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_, float s) : Object(pos, r_, g_, b_, a_), size(s) {
	generatePointsLocal();
}

void Cube::generatePointsLocal() {
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

const float& Cube::getSize() const {
	return size;
}

void Cube::setSize(const float& new_size) {
	const float ratio = new_size / size;
	// calculate the actual center of mass of cube
	// even though it should technically be (0, 0, 0) locally
	// because numerically the points of the cube aren't infinitely precise
	const Vector3D center = getCentroid();
	for (Vector3D& point : points) {
		point = center + (point - center) * ratio;
	}
	size = new_size;
}

Pyramid::Pyramid() : base_size(100.f), height(150.f) {
	generatePointsLocal();
}

void Pyramid::generatePointsLocal() {
	points.clear();

	points.push_back({ -base_size / 2.f, -height / 2.f, -base_size / 2.f });
	points.push_back({ -base_size / 2.f, -height / 2.f,  base_size / 2.f });
	points.push_back({ base_size / 2.f, -height / 2.f,  base_size / 2.f });
	points.push_back({ base_size / 2.f, -height / 2.f, -base_size / 2.f });
	points.push_back({ -base_size / 2.f, -height / 2.f, -base_size / 2.f });
	points.push_back({ 0, height / 2.f, 0 });
	points.push_back({ -base_size / 2.f, -height / 2.f, base_size / 2.f });
	points.push_back({ 0, height / 2.f, 0 });
	points.push_back({ base_size / 2.f, -height / 2.f, base_size / 2.f });
	points.push_back({ 0, height / 2.f, 0 });
	points.push_back({ base_size / 2.f, -height / 2.f, -base_size / 2.f });
}
