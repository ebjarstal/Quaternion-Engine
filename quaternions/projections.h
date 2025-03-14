#pragma once

#include "vectors.h"

extern const int g_Width;
extern const int g_Height;

Vector2D get_camera_to_screen_pos(const Vector3D& p_camera);
