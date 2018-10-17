#ifndef FONT_TEXTURE_H
#define FONT_TEXTURE_H

#include <SDL2/SDL_ttf.h>

#include "texture.h"

class FontTexture : public Texture {

public:

  FontTexture(SDL_Renderer *renderer, std::string const& path = "");
  ~FontTexture();

  bool loadFromFile(std::string const& path, char *text, int size = 24, SDL_Color color = {255, 0, 0});
  
protected:

  TTF_Font *_font;

};


#endif // FONT_TEXTURE_H
