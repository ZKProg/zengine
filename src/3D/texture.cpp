#include "../../include/3D/texture.h"

using namespace std;

Texture::Texture(const char* path_to_texture_file) : _surface(nullptr) {
  
  this->_surface = IMG_Load(path_to_texture_file);

  if (this->_surface == nullptr) {
    cout << "The texture file " << path_to_texture_file << " could not be opened." << endl;
    return;
  }

  glGenTextures(1, &this->_texture_id);
  glBindTexture(GL_TEXTURE_2D, this->_texture_id);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->_surface->w, this->_surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->_surface->pixels);
  glGenerateMipmap(GL_TEXTURE_2D);

}

// CPY CST
Texture::Texture(Texture const& texture) : _surface(nullptr) {
  
  this->_texture_id = texture._texture_id;
  this->_uv = texture._uv;
  this->_surface = texture._surface;
  
}


Texture::~Texture() {

  
  
}

GLuint Texture::getTextureID() {

  return this->_texture_id;
  
}
