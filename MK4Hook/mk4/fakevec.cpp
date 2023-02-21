#include "fakevec.h"
#include "flt.h"

Vector INTVector::ToVector()
{
	return{ int2flt(x), int2flt(y), int2flt(z) };
}

INTVector::INTVector(int a, int b, int c)
{
	x = a;
	y = b;
	z = c;
}

INTVector INTVector::vec2int(Vector* v)
{
	return INTVector(flt2int(v->x), flt2int(v->y), flt2int(v->z));
}
