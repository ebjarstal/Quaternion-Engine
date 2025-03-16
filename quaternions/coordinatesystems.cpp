#include "coordinatesystems.h"




OrthonormalFrame::OrthonormalFrame() {
	frame_vectors[0] = { 1.f, 0.f, 0.f };
	frame_vectors[1] = { 0.f, 1.f, 0.f };
	frame_vectors[2] = { 0.f, 0.f, 1.f };
}

const Vector3D& OrthonormalFrame::getX() const {
	return frame_vectors[0];
}

const Vector3D& OrthonormalFrame::getY() const {
	return frame_vectors[1];
}

const Vector3D& OrthonormalFrame::getZ() const {
	return frame_vectors[2];
}

void OrthonormalFrame::rotate(const Vector3D& axis, const float& angle) {
	rotatePoint(frame_vectors[0], axis, angle);
	rotatePoint(frame_vectors[1], axis, angle);
	rotatePoint(frame_vectors[2], axis, angle);
}





CoordinateSystem::CoordinateSystem() : origin({ 0.f }), frame() {}

CoordinateSystem::CoordinateSystem(Vector3D pos) : origin(pos), frame() {}

OrthonormalFrame& CoordinateSystem::getFrame() {
	return frame;
}

void CoordinateSystem::translate(const float& dx, const float& dy, const float& dz) {
	origin.x += dx;
	origin.y += dy;
	origin.z += dz;
}

void CoordinateSystem::translate(const Vector3D& dv) {
	origin = origin + dv;
}

void CoordinateSystem::moveTo(const Vector3D& pos) {
	origin = pos;
}

void CoordinateSystem::moveTo(const float& dx, const float& dy, const float& dz) {
	origin = { dx, dy, dz };
}

void CoordinateSystem::rotateAroundOrigin(const Vector3D& axis, const float& angle) {
	frame.rotate(axis, angle);
}