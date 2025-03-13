#include "coordinatesystems.h"




OrthonormalFrame::OrthonormalFrame() {
	frame_vectors[0] = { 1.f, 0.f, 0.f };
	frame_vectors[1] = { 0.f, 1.f, 0.f };
	frame_vectors[2] = { 0.f, 0.f, 1.f };
}

const Vector3D& OrthonormalFrame::getX() {
	return frame_vectors[0];
}

const Vector3D& OrthonormalFrame::getY() {
	return frame_vectors[1];
}

const Vector3D& OrthonormalFrame::getZ() {
	return frame_vectors[2];
}

void OrthonormalFrame::rotate(const Vector3D& axis, const float& angle) {
	rotatePoint(frame_vectors[0], axis, angle);
	rotatePoint(frame_vectors[1], axis, angle);
	rotatePoint(frame_vectors[2], axis, angle);
}





CoordinateSystem::CoordinateSystem() : globalPosition({ 0.f }), frame() {}

CoordinateSystem::CoordinateSystem(Vector3D pos) : globalPosition(pos), frame() {}

const Vector3D& CoordinateSystem::getGlobalPosition() const {
	return globalPosition;
}

OrthonormalFrame& CoordinateSystem::getFrame() {
	return frame;
}

void CoordinateSystem::translate(const float& dx, const float& dy, const float& dz) {
	globalPosition.x += dx;
	globalPosition.y += dy;
	globalPosition.z += dz;
}

void CoordinateSystem::rotate(const Vector3D& axis, const float& angle) {
	rotatePoint(globalPosition, axis, angle);
}