#include <SDL3/SDL.h>
#include "vectors.h"
#include "quaternions.h"
#include "rotations.h"
#include "projection3Dto2D.h"
#include <iostream>
#include <vector>
#include <math.h>

constexpr double g_PI = 3.14159265358979323846;
const int g_width = 960;
const int g_height = 720;

struct Cube {
	int size;
	int x, y;
	Vector3D axis;
	float angle;
	std::vector<Vector3D> points;
	Cube() : size(300), x(g_width/2), y(g_height/2), axis({g_width/2, g_height/2, 1}), angle(g_PI / (2.f * 900.f)) {
		for (int x1 = 0; x1 < size; x1++) {
			for (int y1 = 0; y1 < size; y1++) {
				for (int z1 = 0; z1 < size; z1++) {
					Vector3D v{ (float)x + x1 - size / 2, (float)y + y1 - size / 2, (float)z1 - size / 2};
					// left side and right side
					if ((x1 == 0 || x1 == size-1) && (y1 == 0 || y1 == size - 1 || z1 == 0 || z1 == size - 1)) {
						points.push_back(v);
					}
					else if ((y1 == 0 || y1 == size-1) && (z1 == 0 || z1 == size - 1) && (x1 > 0 && x1 < size-1)) {
						points.push_back(v);
					}
				}
			}
		}
	}

	void Draw(SDL_Renderer* renderer);
};

SDL_Window*   window   = nullptr;
SDL_Renderer* renderer = nullptr;

void test_point_rotation();

int main() {
	if (SDL_Init(SDL_INIT_VIDEO) == false) {
		SDL_Log("SDL video subsystem failed to inialize: %s\n", SDL_GetError());
		return -1;
	}
	if (SDL_CreateWindowAndRenderer("Cube", g_width, g_height, 0, &window, &renderer) == false) {
		SDL_Log("SDL window and renderer failed to be created: %s\n", SDL_GetError());
		return -1;
	}

	Vector2D test = get_camera_to_screen_pos({ 400, 100, -200 });
	std::cout << test.x << " " << test.y << "\n";

	Cube cube;

	bool run_app = true;
	while (run_app == true) {
		SDL_Event event;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
		SDL_RenderClear(renderer);
		while (SDL_PollEvent(&event) == true) {
			if (event.type == SDL_EVENT_QUIT) {
				run_app = false;
			}
		}

		cube.Draw(renderer);

		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

void Cube::Draw(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	for (int i = 0; i < points.size(); i++) {
		rotate_point(points[i], axis, angle);
		SDL_RenderPoint(renderer, points[i].x, points[i].y);
	}
}

void test_point_rotation() {
	Vector3D p;        // point to rotate
	Vector3D axis;     // rotation axis
	float angle{ 0 };  // angle of rotation along rotation axis

	// get point coordinates
	std::cout << "coordonnees du point:\n";
	std::cout << "x: ";
	std::cin >> p.x;
	std::cout << "y: ";
	std::cin >> p.y;
	std::cout << "z: ";
	std::cin >> p.z;

	// get rotation axis
	std::cout << "vecteur/axe de rotation:\n";
	std::cout << "x: ";
	std::cin >> axis.x;
	std::cout << "y: ";
	std::cin >> axis.y;
	std::cout << "z: ";
	std::cin >> axis.z;

	// get angle
	std::cout << "angle de rotation (radians): ";
	std::cin >> angle;

	std::cout << "le point " << p << " a pour coordonnees\n";
	rotate_point(p, axis, angle);
	std::cout << p << "\napres une rotation de " << angle << " radians autour du vecteur " << axis << "\n";

}