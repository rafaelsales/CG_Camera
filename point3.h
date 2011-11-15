#ifndef POINT3_H
#define POINT3_H

#include "vector3.h"

class Point3 {
public:
    float x, y, z;
    Point3(float x, float y, float z);
    Point3(const Vector3 & vector);
    ~Point3();

    Point3 operator+(const Vector3 & vector) const;
    Vector3 operator-(const Point3 & other) const;
    float& operator()(unsigned int row);
    const float& operator()(unsigned int row) const;

    Vector3 toVector3() const;
};

#endif // POINT3_H
