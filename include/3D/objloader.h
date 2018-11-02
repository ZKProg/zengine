#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include <glm/glm.hpp>

class ObjLoader {

public:

  ObjLoader(const char *obj_file_path);
  virtual ~ObjLoader();

  std::vector<glm::vec3> getVertices();
  std::vector<glm::vec3> getNormals();
  std::vector<unsigned int> getElements();
  std::vector<glm::vec2> getUvs();

protected:

  std::ifstream _obj_file;
  std::vector<glm::vec3> _vertices;
  std::vector<glm::vec3> _normals, _normals_bag;
  std::vector<glm::vec2> _uvs;
  std::vector<unsigned int> _elements, _normals_indices;
  std::string _content;
  
};

#endif // OBJLOADER_H
