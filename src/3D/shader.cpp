#include "../../include/3D/shader.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTOR
Shader::Shader(const char* vertex, const char* fragment) {

  ////////////////////////////////////////////////////////////////////////////////
  // GL

  _vertex_id = glCreateShader(GL_VERTEX_SHADER);
  _fragment_id = glCreateShader(GL_FRAGMENT_SHADER);

  
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
  this->_program_id = glCreateProgram();
  
  
  if (this->compileVertex() && this->compileFragment()) {

    glAttachShader(this->_program_id, this->_vertex_id);
    glAttachShader(this->_program_id, this->_fragment_id);

  }

  glLinkProgram(this->_program_id);
  GLint resultLink = GL_FALSE;
  int sizeLog;
  
  glGetProgramiv(this->_program_id, GL_LINK_STATUS, &resultLink);
  glGetProgramiv(this->_program_id, GL_INFO_LOG_LENGTH, &sizeLog);

  char log[sizeLog+1];

  if (sizeLog > 0) {
    glGetProgramInfoLog(this->_program_id, sizeLog, NULL, log);
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
  glShaderSource(_vertex_id, 1, &vertex_code, NULL);
  glCompileShader(_vertex_id);

  glGetShaderiv(_vertex_id, GL_COMPILE_STATUS, &result);
  glGetShaderiv(_vertex_id, GL_INFO_LOG_LENGTH, &log_length);

  if (log_length > 0) {
    char log[log_length+1];
    glGetShaderInfoLog(_vertex_id, log_length, NULL, log);
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
  glShaderSource(_fragment_id, 1, &fragment_code, NULL);
  glCompileShader(_fragment_id);

  glGetShaderiv(_fragment_id, GL_COMPILE_STATUS, &result);
  glGetShaderiv(_fragment_id, GL_INFO_LOG_LENGTH, &log_length);
  
  if (log_length > 0) {
    char log[log_length+1];
    glGetShaderInfoLog(_fragment_id, log_length, NULL, log);
    cout << "*----------------------------------------*" << endl;
    cout << log << endl;
  }

  if (result == GL_FALSE) return false;

  return true;
}

GLint Shader::getProgramID() {
  return this->_program_id;
}
