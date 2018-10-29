#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <vector>
#include <fstream>

#include <GL/glew.h>
#include <GL/gl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Texture {

public:
  Texture(const char *path_to_texture_file);
  Texture(Texture const& texture);
  virtual ~Texture();

  GLuint getTextureID();

protected:

  GLuint _texture_id;
  std::vector<float> _uv;
  SDL_Surface *_surface;
  
};



#endif // TEXTURE_H
