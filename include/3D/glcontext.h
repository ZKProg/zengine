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

#include "plane.h"
#include "objmodel.h"

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
    GLuint _vao;

    float _fov;
    glm::mat4 _camera, _projection, _VP;
    glm::vec3 _camera_location, _center_camera_view, _up_camera_vector;
    glm::vec3 _horizontal_camera_vector, _eye_direction;
    std::vector<ObjModel*> *_meshes;
    

};

#endif // GL_CONTEXT_H
