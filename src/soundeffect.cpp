#include "../include/soundeffect.h"

using namespace std;

SoundEffect::SoundEffect(const char* path) :
  Sound(path), _chunk(0)
{
  
  _chunk = Mix_LoadWAV(this->_path);

  if (this->_chunk == nullptr) cout << "Could not load sound effect: " << this->_path << " : " << Mix_GetError() << endl;

}

SoundEffect::~SoundEffect() {


}

void SoundEffect::play() {
  Mix_PlayChannel(-1, this->_chunk, 0);
}

void SoundEffect::stop() {
  Mix_HaltChannel(-1);
}
