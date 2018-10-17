#include "../include/music.h"

using namespace std;

Music::Music(const char* path) : Sound(path), _music(0) {

  this->_music = Mix_LoadMUS(this->_path);

  if (this->_music == nullptr)
    cout << "The music file " << this->_path << " could not be loaded: " << Mix_GetError() << endl;
}

Music::~Music() {
  
}

void Music::play() {

  Mix_PlayMusic(this->_music, 1);
  
}

void Music::stop() {
  Mix_HaltMusic();
}

void Music::pause() {
  Mix_PauseMusic();
}

void Music::resume() {
  Mix_ResumeMusic();
}
