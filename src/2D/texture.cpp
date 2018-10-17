#include "../../include/2D/texture.h"

using namespace std;

Texture::Texture(SDL_Renderer *renderer, string const& path) :
  _texture(0), _renderer(0), _w(0), _h(0)
  {
  this->_renderer = renderer;

  int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    cerr << IMG_GetError() << endl;
  }
  
  if (path != "") {
    this->loadFromFile(path);
  }
}

Texture::~Texture() {
  SDL_DestroyTexture(this->_texture);
}

bool Texture::loadFromFile(string const& path) {

  SDL_Surface *surface = NULL;
  surface = IMG_Load(path.c_str());

  if (surface == nullptr) {
    cerr << SDL_GetError() << endl;
    return false;
  }

  if (this->_renderer != nullptr) {
    this->_texture = SDL_CreateTextureFromSurface(this->_renderer, surface);
  } else {
    cerr << "The renderer point to NULL." << endl;
    return false;
  }

  if (this->_renderer == nullptr) {
    cerr << SDL_GetError() << endl;
    return false;
  }

  this->_w = surface->w;
  this->_h = surface->h;
  
  return true;
}

SDL_Texture *Texture::getLoadedTexture() {
  return this->_texture;
}

int Texture::getWidth() {
  return this->_w;
}

int Texture::getHeight() {
  return this->_h;
}