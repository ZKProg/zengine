#include "../../include/2D/fonttexture.h"

using namespace std;

FontTexture::FontTexture(SDL_Renderer *renderer, string const& path) :
  Texture2D(renderer), _font(0)
{
  TTF_Init();
}

FontTexture::~FontTexture() {

}

bool FontTexture::loadFromFile(const std::string &path, char *text, int size, SDL_Color color) {

  SDL_Surface *surface = 0;

  this->_font = TTF_OpenFont(path.c_str(), size);
  
  surface = TTF_RenderText_Solid(_font, text, color);

  if (surface == nullptr) {
    cerr << TTF_GetError() << endl;
    return false;
  }
  
  this->_texture = SDL_CreateTextureFromSurface(this->_renderer, surface);

  return true;
}
