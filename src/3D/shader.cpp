#include "../../include/3D/shader.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTOR
Shader::Shader(const char* vertex, const char* fragment) {

  ////////////////////////////////////////////////////////////////////////////////
  // GL

  _vertexID = glCreateShader(GL_VERTEX_SHADER);
  _fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

  
  ////////////////////////////////////////////////////////////////////////////////
  // FILE STREAMS
  _vertex_stream.open(vertex, std::ifstream::in);
  _fragment_stream.open(fragment, std::ifstream::in);

  if (!_vertex_stream.is_open()) {
    cout << "Vertex file could not be opened." << endl;
    exit(1);
  }

  if (!_fragment_stream.is_open()) {
    cout << "Fragment file could not be opened." << endl;
    exit(1);
  }

  string current;

  while (getline(_vertex_stream, current)) {

    _vertex_code += current + "\n";

  }

  while (getline(_fragment_stream, current)) {

    _fragment_code += current + "\n";

  }

  ////////////////////////////////////////////////////////////////////////////////
  // PROGRAM
  this->_programID = glCreateProgram();
  
  
  if (this->compileVertex() && this->compileFragment()) {

    glAttachShader(this->_programID, this->_vertexID);
    glAttachShader(this->_programID, this->_fragmentID);

  }

  glLinkProgram(this->_programID);
  GLint resultLink = GL_FALSE;
  int sizeLog;
  
  glGetProgramiv(this->_programID, GL_LINK_STATUS, &resultLink);
  glGetProgramiv(this->_programID, GL_INFO_LOG_LENGTH, &sizeLog);

  char log[sizeLog+1];

  if (sizeLog > 0) {
    glGetProgramInfoLog(this->_programID, sizeLog, NULL, log);
    cout << log << endl;
  }
  
  
}

////////////////////////////////////////////////////////////////////////////////
// DESTRUCTOR
Shader::~Shader() {

  

}

bool Shader::compileVertex() {
  
  GLint result = GL_FALSE;
  int log_length;

  const char *vertex_code = _vertex_code.c_str();
  glShaderSource(_vertexID, 1, &vertex_code, NULL);
  glCompileShader(_vertexID);

  glGetShaderiv(_vertexID, GL_COMPILE_STATUS, &result);
  glGetShaderiv(_vertexID, GL_INFO_LOG_LENGTH, &log_length);

  if (log_length > 0) {
    char log[log_length+1];
    glGetShaderInfoLog(_vertexID, log_length, NULL, log);
    cout << "*----------------------------------------*" << endl;
    cout << log << endl;
  }

  if (result == GL_FALSE) return false;

  return true;
}

bool Shader::compileFragment() {
  
  GLint result = GL_FALSE;
  int log_length;

  const char *fragment_code = _fragment_code.c_str();
  glShaderSource(_fragmentID, 1, &fragment_code, NULL);
  glCompileShader(_fragmentID);

  glGetShaderiv(_fragmentID, GL_COMPILE_STATUS, &result);
  glGetShaderiv(_fragmentID, GL_INFO_LOG_LENGTH, &log_length);

  if (log_length > 0) {
    char log[log_length+1];
    glGetShaderInfoLog(_fragmentID, log_length, NULL, log);
    cout << "*----------------------------------------*" << endl;
    cout << log << endl;
  }

  if (result == GL_FALSE) return false;

  return true;
}

GLint Shader::getProgramID() {
  return this->_programID;
}
