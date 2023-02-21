#include "flt.h"

float int2flt(int data)
{
    return (float)(data * (1.0f / 0xFFFF));
}

int flt2int(float data)
{
    return (int)data * 65536;
}
