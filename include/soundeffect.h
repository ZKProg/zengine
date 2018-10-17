#ifndef SOUND_EFFECT_H
#define SOUND_EFFECT_H

#include "./sound.h"

class SoundEffect : public Sound {

public:

  SoundEffect(const char* path);
  ~SoundEffect();

  virtual void play();
  virtual void stop();

protected:

  Mix_Chunk *_chunk;
};

#endif // SOUND_EFFECT_H
