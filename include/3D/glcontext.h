#ifndef GL_CONTEXT_H
#define GL_CONTEXT_H

#include <iostream>
#include <exception>
#include <vector>

#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "model.h"
#include "plane.h"

class GLContext {

public:
    explicit GLContext(int w = 800, int h = 600);
    virtual ~GLContext();

    bool initGL();
    void paintGL();
    void mainLoop();

    glm::mat4 getMVP();


protected:

    bool _looping;
    SDL_Window *_main_window;
    SDL_Surface *_main_surface;
    SDL_GLContext _gl_context;
    SDL_Event _event;
    int _w, _h;

    float _fov;
    glm::mat4 _camera, _projection, _VP;
    glm::vec3 _camera_location, _center_view, _up_vector;
    std::vector<Plane*> _planes;


};

#endif // GL_CONTEXT_H