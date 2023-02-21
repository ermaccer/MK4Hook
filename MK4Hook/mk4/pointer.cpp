#include "pointer.h"

uintptr_t mk4_ptr::operator*()
{
    return uintptr_t(data * sizeof(int));
}

mk4_ptr::mk4_ptr(uintptr_t d)
{
    data = *(uintptr_t*)d;
}

mk4_ptr::mk4_ptr()
{
}
