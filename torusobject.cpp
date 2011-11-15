#include "torusobject.h"
#include "GL/glut.h"

TorusObject::TorusObject() : innerRadius(1), outerRadius(2), nsides(20), rings(40) {
}

TorusObject::TorusObject(double innerRadius, double outerRadius, int nsides, int rings)
    : innerRadius(innerRadius), outerRadius(outerRadius), nsides(nsides), rings(rings)
{
}

void TorusObject::draw() {
    glutSolidTorus(innerRadius, outerRadius, nsides, rings);
}
