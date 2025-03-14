#pragma once

#include <SDL3/SDL.h>
#include <vector>
#include "vectors.h"
#include "objects.h"

extern const int g_Width;
extern const int g_Height;

extern SDL_Renderer* renderer;

extern const CoordinateSystem g_WorldCoordinateSystem;

void renderObject(const Object& object);