#pragma once
#include "vector.h"

class INTVector {
public:	
	int x, y, z;


	Vector ToVector();
	INTVector(int a, int b, int c);

	static INTVector vec2int(Vector* v);
};