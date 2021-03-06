#include "math/float4.h"

#include <iostream>

#include "utility/convert.h"


// Constr
kl::float4::float4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
kl::float4::float4(float a) : x(a), y(a), z(a), w(a) {}
kl::float4::float4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
kl::float4::float4(const kl::int4& v) : x(float(v.x)), y(float(v.y)), z(float(v.z)), w(float(v.w)) {}
kl::float4::float4(const kl::float2& v, float z, float w) : x(v.x), y(v.y), z(z), w(w) {}
kl::float4::float4(float x, const kl::float2& v, float w) : x(x), y(v.x), z(v.y), w(w) {}
kl::float4::float4(float x, float y, const kl::float2& v) : x(x), y(y), z(v.x), w(v.y) {}
kl::float4::float4(const kl::float2& v1, const kl::float2& v2) : x(v1.x), y(v1.y), z(v2.x), w(v2.y) {}
kl::float4::float4(const kl::float3& v) : x(v.x), y(v.y), z(v.z), w(1.0f) {}
kl::float4::float4(const kl::float3& v, float w) : x(v.x), y(v.y), z(v.z), w(w) {}
kl::float4::float4(float x, const kl::float3& v) : x(x), y(v.x), z(v.y), w(v.z) {}
kl::float4::float4(const kl::color& c) : x(kl::convert::toFloCol(c.r)), y(kl::convert::toFloCol(c.g)), z(kl::convert::toFloCol(c.b)), w(kl::convert::toFloCol(c.a)) {}

// Getters
kl::float3 kl::float4::xyz() const {
	return kl::float3(x, y, z);
}
float& kl::float4::operator[](int i) {
	return data[i];
}
const float& kl::float4::operator[](int i) const {
	return data[i];
}

// Addition
kl::float4 kl::float4::add(const kl::float4& obj) const {
	return kl::float4(x + obj.x, y + obj.y, z + obj.z, w + obj.w);
}
kl::float4 kl::float4::operator+(const kl::float4& obj) const {
	return add(obj);
}
void kl::float4::operator+=(const kl::float4& obj) {
	x += obj.x; y += obj.y; z += obj.z; w += obj.w;
}

// Subtraction
kl::float4 kl::float4::sub(const kl::float4& obj) const {
	return kl::float4(x - obj.x, y - obj.y, z - obj.z, w - obj.w);
}
kl::float4 kl::float4::operator-(const kl::float4& obj) const {
	return sub(obj);
}
void kl::float4::operator-=(const kl::float4& obj) {
	x -= obj.x; y -= obj.y; z -= obj.z; w -= obj.w;
}

// Multiplication
kl::float4 kl::float4::mul(float a) const {
	return kl::float4(x * a, y * a, z * a, w * a);
}
kl::float4 kl::float4::operator*(float a) const {
	return mul(a);
}
void kl::float4::operator*=(float a) {
	x *= a; y *= a; z *= a; w *= a;
}
kl::float4 kl::float4::mul(const kl::float4& obj) const {
	return kl::float4(x * obj.x, y * obj.y, z * obj.z, w * obj.w);
}
kl::float4 kl::float4::operator*(const kl::float4& obj) const {
	return mul(obj);
}
void kl::float4::operator*=(const kl::float4& obj) {
	x *= obj.x; y *= obj.y; z *= obj.z; w *= obj.w;
}

// Division
kl::float4 kl::float4::div(float a) const {
	return mul(1 / a);
}
kl::float4 kl::float4::operator/(float a) const {
	return div(a);
}
void kl::float4::operator/=(float a) {
	operator*=(1 / a);
}
kl::float4 kl::float4::div(const kl::float4& obj) const {
	return kl::float4(x / obj.x, y / obj.y, z / obj.z, w / obj.w);
}
kl::float4 kl::float4::operator/(const kl::float4& obj) const {
	return div(obj);
}
void kl::float4::operator/=(const kl::float4& obj) {
	x /= obj.x; y /= obj.y; z /= obj.z; w /= obj.w;
}

// Comparison
bool kl::float4::equals(const kl::float4& obj) const {
	return x == obj.x && y == obj.y && z == obj.z && w == obj.w;
}
bool kl::float4::operator==(const kl::float4& obj) const {
	return equals(obj);
}
bool kl::float4::operator!=(const kl::float4& obj) const {
	return !equals(obj);
}

// Returns a negated vector
kl::float4 kl::float4::negate() const {
	return mul(-1);
}

// Returns an absolute vector
kl::float4 kl::float4::abso() const {
	return kl::float4(abs(x), abs(y), abs(z), abs(w));
}

// Returns the vectors length
float kl::float4::length() const {
	return sqrt(x * x + y * y + z * z + w * w);
}

// Retruns a normalized vector
kl::float4 kl::float4::normalize() const {
	return div(length());
}

// Returns the dot product
float kl::float4::dot(const kl::float4& a) const {
	return x * a.x + y * a.y + z * a.z + w * a.w;
}

// Returns the angle between the given vector and self
float kl::float4::angle(const kl::float4& a) const {
	return kl::convert::toDegrees(acos(normalize().dot(a.normalize())));
}

// Overloading std::cout
std::ostream& kl::operator<<(std::ostream& os, const kl::float4& obj) {
	os << "(" << obj.x << ", " << obj.y << ", " << obj.z << ", " << obj.w << ")";
	return os;
}
