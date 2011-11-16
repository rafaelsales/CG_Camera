#include <GL/gl.h>
#include <math.h>
#include "matrix4.h"
#include "vector3.h"
#include "point3.h"

Matrix4::Matrix4() {
    // Inicializa como identidade:
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                (*this)(i,j) = 1.0;
            } else {
                (*this)(i,j) = 0.0;
            }
        }
    }
}

Matrix4::~Matrix4(){
}

Matrix4 Matrix4::operator+(const Matrix4 & other) const {
    Matrix4 newMatrix;
    for (int k = 0; k < 4 * 4; k++) {
        newMatrix.matrix[k] = this->matrix[k] + other.matrix[k];
    }
    return newMatrix;
}

Matrix4 Matrix4::operator-(const Matrix4 & other) const {
    Matrix4 newMatrix;
    for (int k = 0; k < 4 * 4; k++) {
        newMatrix.matrix[k] = this->matrix[k] - other.matrix[k];
    }
    return newMatrix;
}

Matrix4 Matrix4::operator*(const Matrix4 & other) const {
    Matrix4 newMatrix;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            newMatrix(i,j) = 0.0;
            for (int k = 0; k < 4; k++) {
                newMatrix(i,j) += (*this)(i,k) * other(k,j);
            }
        }
    }
    return newMatrix;
}

Vector3 Matrix4::operator*(const Vector3 & vector) const {
    float newVector[3] = {0.0, 0.0, 0.0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            newVector[i] += (*this)(i,j) * vector(j);
        }
    }
    return Vector3(newVector[0], newVector[1], newVector[2]);
}
Point3 Matrix4::operator*(const Point3 & point) const {
    float newPoint[3] = {0.0, 0.0, 0.0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            newPoint[i] += (*this)(i,j) * point(j);
        }
    }
    return Point3(newPoint[0], newPoint[1], newPoint[2]);
}

/*
Próximo operador permite:
Matrix4 m;
m(0,0) = 10;
*/
float& Matrix4::operator()(unsigned int row, unsigned int column) {
    return this->matrix[4 * row + column];
}
const float& Matrix4::operator()(unsigned int row, unsigned int column) const {
    return this->matrix[4 * row + column];
}

/* Multiplica a matriz atual do OpenGL com a matriz atual usando glMultMatrix() */
void Matrix4::applyGL() const {
    glMultMatrixf(this->matrix);
}

Matrix4 rotationMatrix(float angle, Vector3 axis) {
    //Q = w + u * sin(angle)
    //w = cos(angle)
    //u é o vetor normalizado do eixo de rotação:
    //u = (axis_x, axis_y, axis_z)

    //Normaliza o eixo e multiplica pelo seno do ângulo:
    axis = sin(angle) * axis.normalize();
    float x = axis.x, x2 = x * x;
    float y = axis.y, y2 = y * y;
    float z = axis.z, z2 = z * z;
    float w = cos(angle), w2 = w * w;

    //Matrix de rotação do quatérnio:
    Matrix4 rotationMatrix;
    rotationMatrix(0,0) = w2 + x2 - y2 - z2;
    rotationMatrix(0,1) = 2 * x * y - 2 * w * z;
    rotationMatrix(0,2) = 2 * x * z + 2 * w * y;
    rotationMatrix(0,3) = 0.0;

    rotationMatrix(1,0) = 2 * x * y + 2 * w * z;
    rotationMatrix(1,1) = w2 - x2 + y2 - z2;
    rotationMatrix(1,2) = 2 * y * z - 2 * w * x;
    rotationMatrix(1,3) = 0.0;

    rotationMatrix(2,0) = 2 * x * z - 2 * w * y;
    rotationMatrix(2,1) = 2 * y * z + 2 * w * x;
    rotationMatrix(2,2) = w2 - x2 - y2 + z2;
    rotationMatrix(2,3) = 0.0;

    rotationMatrix(3,0) = 0.0;
    rotationMatrix(3,1) = 0.0;
    rotationMatrix(3,2) = 0.0;
    rotationMatrix(3,3) = w2 + x2 + y2 + z2;

    //Para rotacionar, basta multiplicar rotationMatrix * Vector3
    return rotationMatrix;
}

Matrix4 translationMatrix(Vector3 displacement) {
    Matrix4 translationMatrix;
    for (int i = 0; i < 3; i++) {
        translationMatrix(i, 3) = displacement(i);
    }
    return translationMatrix;
}

Matrix4 scaleMatrix(float x, float y, float z) {
    Matrix4 scaleMatrix;
    scaleMatrix(0,0) = x;
    scaleMatrix(1,1) = y;
    scaleMatrix(2,2) = z;
    return scaleMatrix;
}
