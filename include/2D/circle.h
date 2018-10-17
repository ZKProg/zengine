#ifndef CIRCLE_H
#define CIRCLE_H

#include "geometry.h"

class Circle : public Geometry {

public:

  Circle(SDL_Renderer *renderer, int radius);
  ~Circle();

  virtual void render(int x, int y);

protected:

  float _radius;

};

#endif // CIRCLE_H
 
