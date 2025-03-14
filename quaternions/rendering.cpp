#include "rendering.h"

void renderObject(const Object& object) {
	std::vector<Vector3D> points = object.getPoints();
	SDL_SetRenderDrawColor(renderer, object.r, object.g, object.b, object.a);
	
	for (int i = 0; i < points.size() - 1; i++) {
		SDL_RenderLine(
			renderer,
			points[i].x + g_Width / 2.f,
			points[i].y + g_Height / 2.f,
			points[i+1].x + g_Width / 2.f,
			points[i+1].y + g_Height / 2.f
		);
	}
}