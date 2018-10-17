#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class Shader {

public:
  explicit Shader(const char* vertex, const char* fragment);
  virtual ~Shader();

  bool compileVertex();
  bool compileFragment();
  bool linkProgram();
  GLint getProgramID();

protected:

  GLint _vertexID, _fragmentID, _programID;
  std::string _vertex_code, _fragment_code;
  std::ifstream _vertex_stream, _fragment_stream;

};



#endif // SHADER_H
