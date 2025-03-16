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
	// TODO
}