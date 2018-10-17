#ifndef MUSIC_H
#define MUSIC_H

#include "./sound.h"

class Music : public Sound {

public:

  Music(const char* path);
  ~Music();

  void play();
  void stop();
  void pause();
  void resume();

protected:

  Mix_Music *_music;

};

#endif // MUSIC_H
