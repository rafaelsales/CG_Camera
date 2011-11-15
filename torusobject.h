#ifndef TORUSOBJECT_H
#define TORUSOBJECT_H

#include "object.h"

class TorusObject : public Object
{
public:
    double innerRadius, outerRadius;
    int nsides, rings;

    TorusObject();
    TorusObject(double innerRadius, double outerRadius, int nsides, int rings);
    void draw();
};

#endif // TORUSOBJECT_H
