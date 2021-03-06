#include "../../include/2D/gameengine.h"

// DEBUG +2
#include "../../include/2D/circle.h"
#include "../../include/soundeffect.h"
// END BLOCK

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// CONST + DEST + CPY

GameEngine::GameEngine(int w, int h, char* title, bool clearLogFile) :
  _mainWindow(0), _mainRenderer(0), _mainSurface(0), _isLooping(false),
  _w(w), _h(h), _title(title)
{
  // Const
  
  // Log file
  if (clearLogFile)
      this->_logFile.open("./log/log.txt", ifstream::out);
  else
      this->_logFile.open("./log/log.txt", ifstream::app);

  if (!this->_logFile.is_open()) {
    cerr << "The log file could not be found and/or opened." << endl;
  }

  this->log("Game Engine Initializing...");

  if (init()) {
    _oldTick = SDL_GetTicks();
  } else {
    const char *err = "The Game Engine could not start properly.";
    this->log(err);
  }

}

GameEngine::~GameEngine() {
  // Destr
}

////////////////////////////////////////////////////////////////////////////////
// METHODS

bool GameEngine::init() {

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    this->log(SDL_GetError());
    return false;
  }

  _mainWindow = SDL_CreateWindow(_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _w, _h, SDL_WINDOW_SHOWN);

  if (_mainWindow == nullptr) {
    this->log(SDL_GetError());
    return false;
  }

  _mainRenderer = SDL_CreateRenderer(_mainWindow, -1, SDL_RENDERER_SOFTWARE);

  if (_mainRenderer == nullptr) {
    this->log(SDL_GetError());
    return false;
  }

  _mainSurface = SDL_GetWindowSurface(_mainWindow);

  if (_mainSurface == nullptr) {
    this->log(SDL_GetError());
    return false;
  }

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    this->log(SDL_GetError());
    return false;
  }

  this->setBackgroundColor();
  
  return true;

}

void GameEngine::mainLoop() {

  // DEBUG BLOCK
  Circle circle(this->_mainRenderer, 250);
  circle.setRenderColor(180, 55, 60);
  circle.render(450, 250);
  SDL_RenderPresent(this->_mainRenderer);

  //SoundEffect effect("./sounds/effects/laser.wav");
  // END BLOCK
  
  _isLooping = true;
  
  while (_isLooping) {

    while (SDL_PollEvent(&this->_event)) {

      if (_event.type == SDL_QUIT) this->_isLooping = false;

      if (_event.type == SDL_KEYDOWN) {

	switch (_event.key.keysym.sym) {

	case SDLK_ESCAPE:
	  this->_isLooping = false;
	  break;

	case SDLK_SPACE:
	  //effect.play();
	  break;
	  
	}
	
      }
      
    }

  }

  this->log("Cleaning before existing...");
  this->clean();
  
}

void GameEngine::clean() {

  SDL_DestroyRenderer(this->_mainRenderer);
  SDL_DestroyWindow(this->_mainWindow);

  SDL_Quit();
  Mix_Quit();

  this->_mainRenderer = 0;
  this->_mainSurface = 0;
  this->_mainWindow = 0;
  
}

void GameEngine::togglePause() {

}

void GameEngine::log(const char *message) {

  time_t t = time(0);
  tm *now = localtime(&t);
  int tick = SDL_GetTicks();
  
  string output =
    to_string(now->tm_hour)
    + ":"
    + to_string(now->tm_min)
    + ":"
    + to_string(now->tm_sec)
    + " => Tick "
    + to_string(tick)
    + " : "
    + static_cast<string>(message);
  
  this->_logFile << output << endl;
  
}

void GameEngine::setBackgroundColor(SDL_Color color) {

  SDL_RenderClear(this->_mainRenderer);
  SDL_Rect full = {0, 0, this->_w, this->_h};
  SDL_SetRenderDrawColor(this->_mainRenderer, color.r, color.g, color.b, 255);
  SDL_RenderFillRect(this->_mainRenderer, &full);
  SDL_RenderPresent(this->_mainRenderer);

}

void GameEngine::setViewport(int x, int y, int w, int h) {

  SDL_Rect viewport = {x, y, w, h};
  SDL_RenderSetViewport(this->_mainRenderer, &viewport);

}

void GameEngine::setFullViewport() {

  SDL_Rect fullViewport = {0, 0, this->_w, this->_h};
  SDL_RenderSetViewport(this->_mainRenderer, &fullViewport);

}

void GameEngine::renderFrame() {

  SDL_RenderPresent(this->_mainRenderer);

}

////////////////////////////////////////////////////////////////////////////////
// GETTERS

SDL_Window *GameEngine::getMainWindow() {
  return this->_mainWindow;
}

SDL_Renderer *GameEngine::getMainRenderer() {
  return this->_mainRenderer;
}

SDL_Surface *GameEngine::getMainSurface() {
  return this->_mainSurface;
}

