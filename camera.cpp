#include "GL/glut.h"
#include "camera.h"
#include "vector3.h"
#include "point3.h"

/* Camera na posição position, olhando para lookTo, direção vertical up */
Camera::Camera(Point3& position, Point3& lookTo, Vector3& up) {
    this->lookTo(position, lookTo, up);
}
Camera::~Camera(){
}

/* Mesmo que construtor */
void Camera::lookTo(Point3& position, Point3& lookTo, Vector3& up) {
    gluLookAt(position.x, position.y, position.z, lookTo.x, lookTo.y, lookTo.z, up.x, up.y, up.z);
}

/* Aplica matriz de posição na matriz GL_MODELVIEW. */
void Camera::glDraw(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/* Aplica matriz de projeção na matriz GL_PROJECTION. */
void Camera::glProjection() {
    glMatrixMode(GL_PROJECTION);
}
