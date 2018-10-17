#ifndef PLANE_H
#define PLANE_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "mesh.h"
#include "shader.h"

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
