#include <SDL3/SDL.h>

// Stuff made by me
#include "vectors.h"
#include "quaternions.h"
#include "rotations.h"
#include "coordinatesystems.h"
#include "projections.h"
#include "tests.h"

// STL
#include <iostream>
#include <vector>
#include <math.h>

const double g_PI = 3.14159265358979323846;

const int g_width  = 960;
const int g_height = 720;

SDL_Window*   window   = nullptr;
SDL_Renderer* renderer = nullptr;

int main() {
	if (SDL_Init(SDL_INIT_VIDEO) == false) {
		SDL_Log("SDL video subsystem failed to inialize: %s\n", SDL_GetError());
		return -1;
	}
	if (SDL_CreateWindowAndRenderer("Cube", g_width, g_height, 0, &window, &renderer) == false) {
		SDL_Log("SDL window and renderer failed to be created: %s\n", SDL_GetError());
		return -1;
	}

	test_coordinate_systems();

	float x, y;

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
		SDL_GetMouseState(&x, &y);

		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}