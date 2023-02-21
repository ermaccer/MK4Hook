#pragma once
#include "..\framework.h"

class mk4_ptr {
public:
	uintptr_t data;

	uintptr_t operator *();

	mk4_ptr(uintptr_t d);
	mk4_ptr();
};