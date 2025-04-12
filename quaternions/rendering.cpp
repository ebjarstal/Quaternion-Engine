#include "rendering.h"

Vector2D calculatePixel(const Camera3D& camera, const Vector3D& point) {
	return camera.getProjectionSurface().getIntersectionPoint({ point, camera.getPositionGlobal() });
}

void renderObject(const Camera3D& camera, const Object& object) {
	const std::vector<Vector3D> points = object.getPointsGlobal();
	SDL_SetRenderDrawColor(renderer, object.r, object.g, object.b, object.a);
	
	for (int i = 0; i < points.size() - 1; i++) {
		const Vector2D pixel1 = calculatePixel(camera, points[i]);
		const Vector2D pixel2 = calculatePixel(camera, points[i + 1]);
		SDL_RenderLine(
			renderer,
			pixel1.x + g_Width / 2.f,
			pixel1.y + g_Height / 2.f,
			pixel2.x + g_Width / 2.f,
			pixel2.y + g_Height / 2.f
		);
	}
}