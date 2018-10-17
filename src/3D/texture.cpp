#include "../../include/3D/texture.h"

using namespace std;

Texture::Texture(const char* path_to_texture_file) : _surface(nullptr) {

  this->_surface = IMG_Load(path_to_texture_file);

  if (this->_surface == nullptr) {
    cout << "The texture file " << path_to_texture_file << " could not be opened." << endl;
  }

  
  

}

// CPY CST
Texture::Texture(Texture const& texture) : _surface(nullptr) {
  
  this->_texture_id = texture._texture_id;
  this->_uv = texture._uv;
  this->_surface = texture._surface;
  
}


Texture::~Texture() {

  delete this->_surface;
  
}

GLuint Texture::getTextureID() {
  
  return this->_texture_id;
  
}
