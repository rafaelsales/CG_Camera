#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vector3.h"
#include "point3.h"

class Camera {
public:
    Camera();
    /* Camera na posição position, olhando para lookTo, direção vertical up */
    Camera(Point3& position, Point3& lookTo, Vector3& up);
    ~Camera();
    
    /* Mesmo que construtor */
    void lookTo(Point3& position, Point3& lookTo, Vector3& up);
    /* Aplica matriz de posição na matriz GL_MODELVIEW. */
    void glDraw();
    /* Aplica matriz de projeção na matriz GL_PROJECTION. */
    void glProjection();
};

#endif
