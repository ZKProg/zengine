#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

#include <glm/glm.hpp>


class ObjLoader {

public:

  ObjLoader(const char *obj_file_path);
  virtual ~ObjLoader();

  std::vector<glm::vec3> getVertices();
  std::vector<glm::vec3> getNormals();
  std::vector<unsigned int> getElements();
  std::vector<glm::vec2> getUvs();

  void displayVector(glm::vec3 const& vector);
  
protected:

  std::ifstream _obj_file;
  std::vector<glm::vec3> _vertices, _vertices_bag;
  std::vector<glm::vec3> _normals, _normals_bag;
  std::vector<glm::vec2> _uvs, _uvs_bag;
  std::vector<unsigned int> _elements;
  std::string _content;

  std::map<std::pair<int, int>, int> _vertex_normal_pairs;
};

#endif // OBJLOADER_H
