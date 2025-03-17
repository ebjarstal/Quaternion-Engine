#include "projections.h"

ProjectionSurface::ProjectionSurface()
	: width(g_Width), height(g_Height), localCoordinateSystem() {

}

ProjectionSurface::ProjectionSurface(Vector3D pos)
	: width(g_Width), height(g_Height), localCoordinateSystem(pos) {

}

ProjectionSurface::ProjectionSurface(int w, int h)
	: width(w), height(h), localCoordinateSystem() {

}

ProjectionSurface::ProjectionSurface(int w, int h, Vector3D pos)
	: width(w), height(h), localCoordinateSystem() {

}

Vector2D ProjectionSurface::getIntersectionPoint(const Ray& ray) const {
	const float t = (float) -ray.getOrigin().z / ray.getDirectionVector().z;
	const Vector3D collision_point = ray.getOrigin() + t * ray.getDirectionVector();
	return { collision_point.x, collision_point.y };
}