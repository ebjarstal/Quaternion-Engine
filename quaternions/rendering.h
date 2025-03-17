#pragma once

#include <SDL3/SDL.h>
#include <vector>
#include "vectors.h"
#include "objects.h"
#include "rays.h"
#include "projections.h"
#include "cameras.h"

extern const int g_Width;
extern const int g_Height;

extern       SDL_Renderer*    renderer;
extern const CoordinateSystem g_WorldCoordinateSystem;

// Renders the given object using the global renderer.
void renderObject(const Camera3D& camera, const Object& object);