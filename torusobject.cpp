#include "torusobject.h"
#include "GL/glut.h"

TorusObject::TorusObject() : innerRadius(0.2), outerRadius(0.7), nsides(10), rings(40) {
}

TorusObject::TorusObject(double innerRadius, double outerRadius, int nsides, int rings)
    : innerRadius(innerRadius), outerRadius(outerRadius), nsides(nsides), rings(rings)
{
}

void TorusObject::draw() {
    glutWireTorus(innerRadius, outerRadius, nsides, rings);
}
