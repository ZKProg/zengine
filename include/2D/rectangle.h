#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "geometry.h"

class Rectangle : public Geometry {

public:

  Rectangle(SDL_Renderer *renderer, int w, int h);
  ~Rectangle();

  virtual void render(int x, int y);

protected:

};


#endif // RECTANGLE_H
