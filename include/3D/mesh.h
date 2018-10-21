#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.h"

class Mesh {

public: 
    Mesh();
    Mesh(Mesh const& mesh);
    virtual ~Mesh();

    virtual void createGeometry();

    virtual void setLocation(glm::vec3 const& location);
    void translate(glm::vec3 const& vector);
    void rotate(float const& angle_rad, glm::vec3 const& axis);

    // Material
    void setAmbient(glm::vec3 const& ambient);

    // Rendering
    virtual void render(glm::mat4 const &VP, int tick, glm::vec3 const& camera_location);

    // Getters
    std::vector<glm::vec3> getVertices();
    

protected:

    std::vector<glm::vec3> _vertex_bag, _vertices, _normals;
    GLuint _program_id;
    GLuint _vbo, _nbo, _ebo;
    Shader *_shader;

    glm::mat4 _model;
    glm::vec3 _location;
    glm::vec3 _ambient;

};

#endif // MESH_H
