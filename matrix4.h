#ifndef MATRIX4_H
#define MATRIX4_H

#include "vector3.h"
#include "point3.h"
#include <GL/gl.h>

class Matrix4
{
public:
    float matrix[4 * 4];
    Matrix4();
    ~Matrix4();

    Matrix4 operator+(const Matrix4 & other) const;
    Matrix4 operator-(const Matrix4 & other) const;
    Matrix4 operator*(const Matrix4 & other) const;

    Vector3 operator*(const Vector3 & vector) const;
    Point3 operator*(const Point3 & point) const;

    /*
    Próximo operador permite:
    Matrix4 m;
    m(0,0) = 10;
    */
    float& operator()(unsigned int row, unsigned int column);
    const float& operator()(unsigned int row, unsigned int column) const;

    /* Multiplica a matriz atual do OpenGL com a matriz atual usando glMultMatrix() */
    void applyGL() const;
};

Matrix4 rotationMatrix(float angle, Vector3 axis); /* Matrix de rotação geral por ângulo angle e eixo de rotação axis */
Matrix4 translationMatrix(Vector3 displacement); /* Matriz de translação com veto displacement */
Matrix4 scaleMatrix(float x, float y, float z); /* Matriz de escala */

#endif // MATRIX4_H
