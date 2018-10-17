#include "../../include/2D/geometry.h"

using namespace std;

Geometry::Geometry(SDL_Renderer *renderer) : Asset(), _renderer(0), _w(0), _h(0) {

  this->_renderer = renderer;

  // Default Color
  _renderColor = {255, 0, 0};
  this->setRenderColor(_renderColor);
  
}

Geometry::~Geometry() {

}

void Geometry::render() {

}

void Geometry::setRenderColor(SDL_Color const& color) {

  this->_renderColor = color;
  SDL_SetRenderDrawColor(this->_renderer, color.r, color.g, color.b, 255);

}

void Geometry::setRenderColor(int r, int g, int b, int a) {

  SDL_SetRenderDrawColor(this->_renderer, r, g, b, a);

}
