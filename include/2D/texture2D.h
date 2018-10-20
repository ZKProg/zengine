#ifndef Texture2D_H
#define Texture2D_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>

class Texture2D {

 public:

  Texture2D(SDL_Renderer *renderer, std::string const& path = "");
  ~Texture2D();

  virtual bool loadFromFile(std::string const& path);
  SDL_Texture *getLoadedTexture();
  
  int getWidth();
  int getHeight();
  
 protected:

  SDL_Renderer *_renderer;
  SDL_Texture *_texture;

  int _w, _h;
  
};

#endif // Texture2D_H
