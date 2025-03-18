#include "rendering.h"

void renderObject(const Camera3D& camera, const Object& object) {
	const std::vector<Vector3D> points = object.getPointsGlobal();
	SDL_SetRenderDrawColor(renderer, object.r, object.g, object.b, object.a);
	
	for (int i = 0; i < points.size() - 1; i++) {
		const Ray ray1{ points[i], camera.getPositionGlobal() };
		const Vector2D point1 = camera.getProjectionSurface().getIntersectionPoint(ray1);
		const Ray ray2{ points[i+1], camera.getPositionGlobal() };
		const Vector2D point2 = camera.getProjectionSurface().getIntersectionPoint(ray2);
		SDL_RenderLine(
			renderer,
			point1.x + g_Width / 2.f,
			point1.y + g_Height / 2.f,
			point2.x + g_Width / 2.f,
			point2.y + g_Height / 2.f
		);
	}
}