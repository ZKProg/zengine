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

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/mesh.h>
#include <assimp/scene.h>

#include "shader.h"
#include "texture.h"

class Mesh {

public: 
  Mesh();
  Mesh(aiMesh* mesh, aiMesh* parent_node = nullptr);
  Mesh(Mesh const& mesh);
  virtual ~Mesh();

  virtual void createGeometry();
  virtual void setLocation(glm::vec3 const& location);
  
  void translate(glm::vec3 const& vector);
  void rotate(float const& angle_rad, glm::vec3 const& axis);

  // Material
  void setAmbient(glm::vec3 const& ambient);

  // Rendering
  virtual void render(glm::mat4 const &VP, int tick,
		      glm::vec3 const& camera_location,
		      bool draw_elements = true);
  
  void initBufferData();

  // Getters
  std::vector<glm::vec3> getVertices();
  std::vector<unsigned int> getElements();

  // Setters
  void setVertices(std::vector<glm::vec3> const& vertices);
  void setNormals(std::vector<glm::vec3> const& normals);
  void setElements(std::vector<unsigned int> const& elements);
  void setShaders(const char* vertex, const char* fragment);
  void setUvs(std::vector<glm::vec2> const& uvs);
  void addTexture(Texture const& texture);
    

protected:

  void createBuffers();

  std::vector<glm::vec3> _vertex_bag, _vertices, _normals;
  std::vector<glm::vec2> _uvs;
  std::vector<unsigned int> _elements;
  std::vector<Texture> _textures;
 
  GLuint _vbo, _nbo, _ebo, _ubo, _program_id;
  Shader *_shader;
  aiMesh *_parent_node;

  glm::mat4 _model;
  glm::vec3 _location, _ambient;

};

#endif // MESH_H
