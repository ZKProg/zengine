#include "../../include/2D/rectangle.h"

using namespace std;

Rectangle::Rectangle(SDL_Renderer *renderer, int w, int h) : Geometry(renderer) {

  this->_w = w;
  this->_h = h;

}

Rectangle::~Rectangle() {

}

void Rectangle::render(int x, int y) {

  SDL_Rect rect = {x, y, _w, _h};
  SDL_RenderFillRect(this->_renderer, &rect);
  
}
