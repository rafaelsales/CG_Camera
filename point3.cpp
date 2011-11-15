#include "point3.h"
#include "vector3.h"

Point3::Point3(float x, float y, float z): x(x), y(y), z(z) {
}

Point3::Point3(const Vector3 & vector) : x(vector.x), y(vector.y), z(vector.z) {
}

Point3::~Point3() {
}

Point3 Point3::operator+(const Vector3 & vector) const {
    Point3 newPoint(this->x + vector.x, this->y + vector.y, this->z + vector.z);
    return newPoint;
}

Vector3 Point3::operator-(const Point3 & other) const {
    Vector3 newVector(this->x - other.x, this->y - other.y, this->z - other.z);
    return newVector;
}

float& Point3::operator()(unsigned int row) {
    switch (row) {
    case 0: return x;
    case 1: return y;
    case 2: return z;
    }
    return z;
}

const float& Point3::operator()(unsigned int row) const {
    switch (row) {
    case 0: return x;
    case 1: return y;
    case 2: return z;
    }
    return z;
}

Vector3 Point3::toVector3() const {
    Vector3 newVector(this->x, this->y, this->z);
    return newVector;
}
