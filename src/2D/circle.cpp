#include "../../include/2D/circle.h"

using namespace std;

Circle::Circle(SDL_Renderer *renderer, int radius) :
  Geometry(renderer), _radius(radius)
{

 
}

Circle::~Circle() {

}

void Circle::render(int x, int y) {

  for (float i = 0; i < (float)this->_radius; i += 1.0f) {

    for (float j = 0; j < 360.0f; j += 0.1f) {

      float alphaRad = (3.14159f * j ) / 180.0f;

      float newx = cos(alphaRad) * i;
      float newy = sin(alphaRad) * i;

      SDL_RenderDrawPoint(this->_renderer, x + newx, y + newy);

    }
  }
  
}
