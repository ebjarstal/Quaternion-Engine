#include "projection3Dto2D.h"

Vector2D get_camera_to_screen_pos(const Vector3D& p_camera) {
	return {
		(float)p_camera.x + g_width/2,
		(float)p_camera.y + g_height/2
	};
}