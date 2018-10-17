#include <iostream>
#include <thread>

#include <SDL2/SDL_image.h>

#include "configure/conf.h"

#include "./include/3D/glcontext.h"
#include "./include/2D/gameengine.h"

using namespace std;

int main(int argc, char **argv) {

  cout << "Zengine launching..." << endl;
  cout << "Version " << zengine_VERSION_MAJOR << "." << zengine_VERSION_MINOR << endl;

  // Initialize features that are common to both 3D and 2D environments
  int flags = IMG_INIT_JPG | IMG_INIT_PNG;
  int init = IMG_Init(flags);
  if (init != (init & flags)) {

    cout << "SDL Image could not be initialized." << endl;
    return 1;
    
  }

  // Here goes the environment(s) chosen for the program to run
  GLContext *context = new GLContext();
  context->mainLoop();

  
  delete context;
  return 0;
}

