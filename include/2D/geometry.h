#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "asset.h"

class Geometry : public Asset {

public:
  Geometry(SDL_Renderer *renderer);
  virtual ~Geometry();

  virtual void render();
 
  void setRenderColor(SDL_Color const& color);
  void setRenderColor(int r, int g, int b, int a = 255);
  int getWidth();
  int getHeight();
  
protected:

  SDL_Renderer *_renderer;
  int _w, _h;
  SDL_Color _renderColor;

};

#endif GEOMETRY_H
