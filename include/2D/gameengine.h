#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <iostream>
#include <fstream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <ctime>

class GameEngine {

public:
  GameEngine(int w = 800, int h = 600, char* title = "ZK Game", bool clearLogFile = false);
  virtual ~GameEngine();

  bool init();
  void mainLoop();
  void clean();
  void togglePause();
  void log(const char *message);

  void setBackgroundColor(SDL_Color color = {100, 100, 100});
  void setViewport(int x, int y, int w, int h);
  void setFullViewport();
  void renderFrame();
  
  SDL_Renderer *getMainRenderer();
  SDL_Surface *getMainSurface();
  SDL_Window *getMainWindow();

protected:

  SDL_Window *_mainWindow;
  SDL_Renderer *_mainRenderer;
  SDL_Surface *_mainSurface;
  SDL_Event _event;
  std::ofstream _logFile;
  bool _isLooping;
  int _w, _h;
  char *_title;
  int _oldTick;

};

#endif // GAME_ENGINE_H
