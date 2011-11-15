#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
public:
    float x, y, z;
    Vector3(float x, float y, float z);
    ~Vector3();

    Vector3 operator+(const Vector3 &other) const;
    Vector3 operator-(const Vector3 &other) const;
    float& operator()(unsigned int row);
    const float& operator()(unsigned int row) const;

    Vector3 normalize() const;
    float length() const;
    float squaredLength() const;
};

float dotProduct(const Vector3 & v1, const Vector3 & v2);
Vector3 crossProduct(const Vector3 & v1, const Vector3 & v2);

Vector3 operator*(float value, const Vector3 & vector);
Vector3 operator*(const Vector3 & vector, float value);

Vector3 operator/(float value, const Vector3 & vector);
Vector3 operator/(const Vector3 & vector, float value);

#endif // VECTOR3_H
