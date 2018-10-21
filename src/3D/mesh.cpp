#include "../../include/3D/mesh.h"

using namespace std;

Mesh::Mesh() : _shader(0) { 

  glCreateBuffers(1, &_vbo);
  glCreateBuffers(1, &_nbo);
  glCreateBuffers(1, &_ebo);
  
}

Mesh::Mesh(Mesh const& mesh) : _shader(0) {
  //this->_shader = new Shader(*(mesh._shader));
}

Mesh::~Mesh() {

}

void Mesh::createGeometry() {}


void Mesh::setLocation(glm::vec3 const& location) {
  
  this->_vertices.clear();
  this->_location = location;

}

void Mesh::translate(glm::vec3 const& vector) {

  this->_model = glm::translate(this->_model, vector);
}

void Mesh::rotate(float const& angle_rad, glm::vec3 const& axis) {

  this->_model = glm::rotate(this->_model, angle_rad, axis);

}

void Mesh::setAmbient(glm::vec3 const& ambient) {
    this->_ambient = ambient;
}

void Mesh::render(glm::mat4 const &VP, int tick, glm::vec3 const& camera_location) {

    // Rendering function
        glm::mat4 _VP = VP * this->_model;

    glUseProgram(this->_program_id);

    GLint hookMVP = glGetUniformLocation(this->_program_id, "MVP");
    GLint hookTIME = glGetUniformLocation(this->_program_id, "time");
    GLint hookAMBIENT = glGetUniformLocation(this->_program_id, "ambient");
    GLint hookCAMERA = glGetUniformLocation(this->_program_id, "camera");
    
    glUniformMatrix4fv(hookMVP, 1, GL_FALSE, reinterpret_cast<GLfloat*>(&_VP[0][0]));
    glUniform1f(hookTIME, (float)tick);
    glUniform3fv(hookAMBIENT, 1, reinterpret_cast<const GLfloat*>(&this->_ambient[0]));
    glUniform3fv(hookCAMERA, 1, reinterpret_cast<const GLfloat*>(&camera_location[0]));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, _nbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glDrawArrays(GL_TRIANGLES, 0, this->_vertices.size() * 3);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glUseProgram(0);


}

vector<glm::vec3> Mesh::getVertices() {
    return this->_vertices;
}
