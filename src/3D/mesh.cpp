#include "../../include/3D/mesh.h"

using namespace std;

Mesh::Mesh() : _shader(0), _parent_node(0)  { 

  this->_model = glm::mat4(1.0f);
  this->createBuffers();
  
}

Mesh::Mesh(aiMesh *mesh, aiMesh *parent_node) :
  _shader(0), _parent_node(0)
{

  this->_parent_node = parent_node;
  this->_model = glm::mat4(1.0f);
  this->createBuffers();

  
}

Mesh::Mesh(Mesh const& mesh) : _shader(0) {
  //this->_shader = new Shader(*(mesh._shader));
}

Mesh::~Mesh() {

  delete this->_shader;
  
}

void Mesh::createBuffers() {

  glGenBuffers(1, &_vbo);
  glGenBuffers(1, &_nbo);
  glGenBuffers(1, &_ebo);
  glGenBuffers(1, &_ubo);

}

/**
 * After the geometry is created, the initBufferData method must be called.
 */
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

void Mesh::render(glm::mat4 const &VP, int tick, glm::vec3 const& camera_location, bool draw_elements) {

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
  glEnableVertexAttribArray(2);

  glBindBuffer(GL_ARRAY_BUFFER, _vbo);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

  glBindBuffer(GL_ARRAY_BUFFER, _nbo);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

  glBindBuffer(GL_ARRAY_BUFFER, _ubo);
  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

  if (this->_textures.size() > 0) {
    glBindTexture(GL_TEXTURE_2D, this->_textures.at(0).getTextureID());
  }
  
  if (draw_elements) {

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glDrawElements(GL_TRIANGLES, this->_elements.size(), GL_UNSIGNED_INT, (void*)0);
    
  } else {
    
    glDrawArrays(GL_TRIANGLES, 0, this->_vertices.size() * 3);

  }

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(2);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glUseProgram(0);


}

vector<glm::vec3> Mesh::getVertices() {
  return this->_vertices;
}

vector<unsigned int> Mesh::getElements() {
  return this->_elements;
}

void Mesh::setVertices(std::vector<glm::vec3> const& vertices) {
  this->_vertices = vertices;
}

void Mesh::setNormals(std::vector<glm::vec3> const& normals) {
  this->_normals = normals;
}

void Mesh::setElements(std::vector<unsigned int> const& elements) {

  this->_elements = elements;
 
}

void Mesh::setShaders(const char *vertex, const char* fragment) {

  if (this->_shader != nullptr) delete this->_shader;

  this->_shader = new Shader(vertex, fragment);
  this->_program_id = this->_shader->getProgramID();
}

void Mesh::setUvs(vector<glm::vec2> const& uvs) {
  this->_uvs = uvs;
}

void Mesh::addTexture(Texture const& texture) {
  this->_textures.push_back(texture);
}

void Mesh::initBufferData() {

  glBindBuffer(GL_ARRAY_BUFFER, _vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->_vertices.size() * 3, this->_vertices.data(), GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, _nbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->_normals.size() * 3, this->_normals.data(), GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, _ubo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->_uvs.size() * 2, this->_uvs.data(), GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * this->_elements.size(), this->_elements.data(), GL_STATIC_DRAW);

}

