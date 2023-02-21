#pragma once
#include <math.h>

class Vector
{
public:
	float x, y, z;
	Vector(void) {}
	Vector(float a, float b, float c)
	{
		x = a;
		y = b;
		z = c;
	}
	float Heading(void) const { return atan2(-x, y); }
	float Magnitude(void) const { return sqrt(x * x + y * y + z * z); }
	float MagnitudeSqr(void) const { return x * x + y * y + z * z; }
	float Magnitude2D(void) const { return sqrt(x * x + y * y); }
	float MagnitudeSqr2D(void) const { return x * x + y * y; }
	void Normalise();

	const Vector& operator+=(Vector const& right) {
		x += right.x;
		y += right.y;
		z += right.z;
		return *this;
	}

	const Vector& operator+=(float const& right) {
		x += right;
		y += right;
		z += right;
		return *this;
	}

	const Vector& operator-=(Vector const& right) {
		x -= right.x;
		y -= right.y;
		z -= right.z;
		return *this;
	}

	const Vector& operator*=(float right) {
		x *= right;
		y *= right;
		z *= right;
		return *this;
	}

	const Vector& operator/=(float right) {
		x /= right;
		y /= right;
		z /= right;
		return *this;
	}

	Vector operator-() const {
		return Vector(-x, -y, -z);
	}
};

inline Vector operator+(const Vector& left, const Vector& right)
{
	return Vector(left.x + right.x, left.y + right.y, left.z + right.z);
}

inline Vector operator-(const Vector& left, const Vector& right)
{
	return Vector(left.x - right.x, left.y - right.y, left.z - right.z);
}

inline Vector operator*(const Vector& left, float right)
{
	return Vector(left.x * right, left.y * right, left.z * right);
}

inline Vector operator*(float left, const Vector& right)
{
	return Vector(left * right.x, left * right.y, left * right.z);
}

inline Vector operator/(const Vector& left, float right)
{
	return Vector(left.x / right, left.y / right, left.z / right);
}

Vector CrossProduct(const Vector& v1, const Vector& v2);