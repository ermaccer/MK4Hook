#pragma once
#include "mk4.h"
#include "wrapper.h"

class FreeCamera {
public:
	static bool   freezeCam;
	static Vector camPos;
	static Vector camRot;

	static void Update();
};

void camera_hook_one();
void camera_hook_two();
void camera_hook_three();
void camera_angle_hook_one();
void camera_angle_hook_two();
void camera_angle_hook_three();
void camera_update_hook_one();
void camera_update_hook_two();
void camera_update_hook_three();
void camera_update_angle_hook_one();
void camera_update_angle_hook_two();
void camera_update_angle_hook_three();


void camera_special_hook_one();
void camera_special_hook_two();
void camera_special_hook_three();

void camera_special_angle_hook_x();


void camera_special_angle_hook_one();
void camera_special_angle_hook_two();
void camera_special_angle_hook_three();


void camera_special_angle2_hook_one();
void camera_special_angle2_hook_two();
void camera_special_angle2_hook_three();

void camera_special_more_hook_one();
void camera_special_more_hook_two();
void camera_special_more_hook_three();
void camera_special_more_hook_four();

void camera_special_more_angle_hook_one();
void camera_special_more_angle_hook_two();