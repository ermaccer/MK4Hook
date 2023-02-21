#include "wrapper.h"

void _set_camera_xyz(Vector* pos)
{
	INTVector v = INTVector::vec2int(pos);
    mk4_ptr cam(0x524ED0);
    uintptr_t ptr = *cam;
    *(int*)(ptr + 0x54) = v.x;
    *(int*)(ptr + 0x58) = v.y;
    *(int*)(ptr + 0x5C) = v.z;
}

void _set_camera_angle(Vector* pos)
{
    INTVector v = INTVector::vec2int(pos);
    mk4_ptr cam(0x524ED0);
    uintptr_t ptr = *cam;
    *(int*)(ptr + 0x60) = v.x;
    *(int*)(ptr + 0x64) = v.y;
    *(int*)(ptr + 0x68) = v.z;
}

void _get_camera_xyz(Vector* pos)
{
    mk4_ptr cam(0x524ED0);
    uintptr_t ptr = *cam;

    if (ptr)
    {
        INTVector _i = *(INTVector*)(ptr + 0x54);
        Vector v = _i.ToVector();
        *pos = v;
    }
}

void _get_camera_angle(Vector* pos)
{
    mk4_ptr cam(0x524ED0);
    uintptr_t ptr = *cam;

    if (ptr)
    {
        INTVector _i = *(INTVector*)(ptr + 0x70);
        Vector v = _i.ToVector();
        *pos = v;
    }
}

INTVector _get_camera_xyz_int()
{
    mk4_ptr cam(0x524ED0);
    uintptr_t ptr = *cam;
    INTVector result(0,0,0);
    if (ptr)
    {
        result= *(INTVector*)(ptr + 0x54);
    }
    return result;
}
