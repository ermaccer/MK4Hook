#include "camera.h"

void set_camera_xyz(INTVector* data)
{
	((void(__cdecl*)(INTVector*))0x4313C0)(data);
}

uintptr_t get_camera()
{
    mk4_ptr cam(0x524ED0);
    uintptr_t ptr = *cam;
    return ptr;
}

uintptr_t get_raw_camera()
{
    return *(uintptr_t*)0x524ED0;
}
