#include "rendering.h"

void renderObject(const Camera3D& camera, const Object& object) {
	const std::vector<Vector3D> points = object.getPointsGlobal();
	SDL_SetRenderDrawColor(renderer, object.r, object.g, object.b, object.a);
	
	for (int i = 0; i < points.size(); i++) {
		const Ray ray1{ points[i], camera.getPositionGlobal() };
		const Vector2D point1 = camera.getProjectionSurface().getIntersectionPoint(ray1);
		SDL_RenderPoint(
			renderer,
			point1.x + g_Width / 2.f,
			point1.y + g_Height / 2.f
		);
	}
}