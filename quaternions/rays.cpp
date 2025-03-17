#include "rays.h"

Ray::Ray(Vector3D o, Vector3D t) : origin(o), target(t) {

}

void Ray::setOrigin(const Vector3D& new_origin) {
	origin = new_origin;
}
void Ray::setTarget(const Vector3D& new_target) {
	target = new_target;
}

const Vector3D& Ray::getOrigin() const {
	return origin;
}

const Vector3D& Ray::getTarget() const {
	return target;
}

Vector3D Ray::getDirectionVector() const {
	return (target - origin);
}

float Ray::getLength() const {
	return (target - origin).getNorm();
}