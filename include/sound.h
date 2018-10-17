#ifndef SOUND_H
#define SOUND_H

#include <iostream>
#include <SDL2/SDL_mixer.h>

class Sound {

public:

  Sound(const char* path);
  virtual ~Sound();

  virtual void play() = 0;
  virtual void stop() = 0;
  
protected:

  const char* _path;

};

#endif // SOUND_H
