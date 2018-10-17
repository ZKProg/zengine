#include <iostream>
#include <thread>

#include "configure/conf.h"

#include "./include/3D/glcontext.h"
#include "./include/2D/gameengine.h"

using namespace std;

int main(int argc, char **argv) {

  cout << "Zengine launching..." << endl;
  cout << "Version " << zengine_VERSION_MAJOR << "." << zengine_VERSION_MINOR << endl;

  /**
  GLContext context = GLContext();
  context.mainLoop();

  OR

  GameEngine gameEngine(800, 600, "2D Engine");
  gameEngine.mainLoop();
  **/
  
  return 0;
}
