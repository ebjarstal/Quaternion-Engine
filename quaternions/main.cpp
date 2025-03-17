#include <SDL3/SDL.h>

// Stuff made by me
#include "vectors.h"
#include "quaternions.h"
#include "rotations.h"
#include "coordinatesystems.h"
#include "projections.h"
#include "rays.h"
#include "objects.h"
#include "rendering.h"
#include "tests.h"

// STL
#include <iostream>
#include <vector>
#include <math.h>

const double g_PI     = 3.14159265358979323846;
const int    g_Width  = 960;
const int    g_Height = 720;

SDL_Window*   window   = nullptr;
SDL_Renderer* renderer = nullptr;

const CoordinateSystem g_WorldCoordinateSystem;
Camera3D g_Camera({ 0.f, 0.f, 10.f });

int main() {
	if (SDL_Init(SDL_INIT_VIDEO) == false) {
		SDL_Log("SDL video subsystem failed to inialize: %s\n", SDL_GetError());
		return -1;
	}
	if (SDL_CreateWindowAndRenderer("Cube", g_Width, g_Height, 0, &window, &renderer) == false) {
		SDL_Log("SDL window and renderer failed to be created: %s\n", SDL_GetError());
		return -1;
	}

	ProjectionSurface ps1;
	Ray r1{ {2, 2, -5}, {0, 0, 10} };
	std::cout << ps1.getIntersectionPoint(r1) << "\n";

	Cube cube(200.f);
	cube.moveTo({ 0, 0, -50});
	cube.setColor(0xFF, 0x00, 0x00, 0xFF);
	float x, y;

	bool rotate_cube = false;
	bool run_app = true;
	while (run_app == true) {
		SDL_Event event;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
		SDL_RenderClear(renderer);
		while (SDL_PollEvent(&event) == true) {
			if (event.type == SDL_EVENT_QUIT) {
				run_app = false;
			}
			if (event.type == SDL_EVENT_KEY_DOWN) {
				if (event.key.scancode == SDL_SCANCODE_R) {
					rotate_cube = !rotate_cube;
				}
				if (event.key.scancode == SDL_SCANCODE_UP) {
					cube.translate({ 0.f, -10.f, 0.f });
				}
				if (event.key.scancode == SDL_SCANCODE_DOWN) {
					cube.translate({ 0.f, 10.f, 0.f });
				}
				if (event.key.scancode == SDL_SCANCODE_RIGHT) {
					cube.translate({ 10.f, 0.f, 0.f });
				}
				if (event.key.scancode == SDL_SCANCODE_LEFT) {
					cube.translate({ -10.f, 0.f, 0.f });
				}
			}
			if (event.type == SDL_EVENT_MOUSE_MOTION) {
				if (SDL_GetMouseState(&x, &y) == 1) {
					cube.moveTo(x - g_Width / 2.f, y - g_Height / 2.f, 0);
				}
			}
			if (event.type == SDL_EVENT_MOUSE_WHEEL) {
				cube.setSize(cube.getSize() + event.wheel.y);
			}
		}

		if (rotate_cube == true) cube.rotateAroundCenter({ 1.f, 1.f, 1.f }, g_PI / (2.f * 3600.f));
		renderObject(g_Camera, cube);

		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}