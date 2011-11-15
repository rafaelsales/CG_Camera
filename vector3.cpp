#include "vector3.h"
#include "math.h"

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {
}

Vector3::~Vector3() {
}

Vector3 Vector3::operator+(const Vector3 &other) const {
    const Vector3 newVector(this->x + other.x, this->y + other.y, this->z + other.z);
    return newVector;
}

Vector3 Vector3::operator-(const Vector3 &other) const {
    const Vector3 newVector(this->x - other.x, this->y - other.y, this->z - other.z);
    return newVector;
}

float& Vector3::operator()(unsigned int row) {
    switch (row) {
    case 0: return x;
    case 1: return y;
    case 2: return z;
    }
    return z;
}

const float& Vector3::operator()(unsigned int row) const {
    switch (row) {
    case 0: return x;
    case 1: return y;
    case 2: return z;
    }
    return z;
}

Vector3 Vector3::normalize() const {
    float length = this->length();
    const Vector3 normalized(x/length, y/length, z/length);
    return normalized;
}

float Vector3::length() const {
    return sqrt(x*x + y*y + z*z);
}

float Vector3::squaredLength() const {
    return x*x + y*y + z*z;
}

float dotProduct(const Vector3 & v1, const Vector3 & v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector3 crossProduct(const Vector3 & v1, const Vector3 & v2) {
    // (i(Ay.Vz - Az.Vy) - j(Ax.Bz + Az.Bx) + k(Ax.By - Ay.Bx)
    const Vector3 newVector(v1.y*v2.z - v1.z * v2.y, - v1.x*v2.z + v1.z*v2.x, v1.x*v2.y - v1.y*v2.x);
    return newVector;
}

Vector3 operator*(float value, const Vector3 & vector) {
    Vector3 newVector(value * vector.x, value * vector.y, value * vector.z);
    return newVector;
}

Vector3 operator*(const Vector3 & vector, float value) {
    Vector3 newVector(value * vector.x, value * vector.y, value * vector.z);
    return newVector;
}

Vector3 operator/(float value, const Vector3 & vector) {
    Vector3 newVector(vector.x / value, vector.y / value, vector.z / value);
    return newVector;
}

Vector3 operator/(const Vector3 & vector, float value) {
    Vector3 newVector(vector.x / value, vector.y / value, vector.z / value);
    return newVector;
}
