#ifndef PLANE_H
#define PLANE_H

#include "mesh.h"

class Plane : public Mesh {

public:
    explicit Plane(float w = 10, float h = 10, float step = 0.1f);
    virtual ~Plane();

    // Geometry
    virtual void createGeometry();
    
protected:

    float _w, _h, _step;
    
};



#endif // PLANE_H
