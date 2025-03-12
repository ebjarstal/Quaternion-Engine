#include <SDL3/SDL.h>
#include "vectors.h"
#include "quaternions.h"
#include "rotations.h"
#include <iostream>
#include <math.h>

constexpr double g_PI = 3.14159265358979323846;
constexpr int g_width = 960;
constexpr int g_height = 720;

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
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
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