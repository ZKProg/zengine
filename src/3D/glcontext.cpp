#include "../../include/3D/glcontext.h"

using namespace std;

GLContext::GLContext(int w, int h) : 
    _looping(false), _main_surface(nullptr), _main_window(nullptr), _w(w), _h(h)
{
    // Camera settings
    this->_camera_location = glm::vec3(2, 2, 2);
    this->_center_camera_view = glm::vec3(0,0,0);
    this->_up_camera_vector = glm::vec3(0,1,0);
    this->_fov = 60.0f;
    this->_horizontal_camera_vector = glm::normalize( glm::cross(
        this->_center_camera_view - this->_camera_location,
        this->_up_camera_vector
    ));
    this->_eye_direction = this->_center_camera_view - this->_camera_location;

    try {
        if (!this->initGL()) throw "Window initializing failed.";
    } catch (exception e) {
        cout << e.what() << endl;
        exit(1);
    }

}

GLContext::~GLContext() {

    SDL_FreeSurface(this->_main_surface);
    SDL_DestroyWindow(this->_main_window);
    SDL_Quit();

}

bool GLContext::initGL() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << SDL_GetError() << endl;
        return false;
    }

    _main_window = SDL_CreateWindow("ZKProg mesh gen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _w, _h, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if (this->_main_window == nullptr) {
        cout << SDL_GetError() << endl;
        return false;
    }

    _main_surface = SDL_GetWindowSurface(this->_main_window);

    if (this->_main_surface == nullptr) {
        cout << SDL_GetError() << endl;
        return false;
    }

    this->_gl_context = SDL_GLContext(this->_main_window);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);    
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // -----------------------------------------------------------------------------
    // OPENGL

    GLenum glew = glewInit();

    if (glew != GLEW_OK) {
        cout << glewGetErrorString(glew) << endl;
        return false;
    }

    glEnable(GL_DEPTH_TEST);
    glCreateVertexArrays(1, &this->_vao);
    glBindVertexArray(this->_vao);

    // Linear algebra
     _camera = glm::lookAt(
        this->_camera_location,
        this->_center_camera_view,
        this->_up_camera_vector
    );

    _projection = glm::perspectiveFov(glm::radians(this->_fov), (float)this->_w, (float)this->_h, 0.1f, 1000.0f);    

    // Init meshes to display here
    Plane *plane = new Plane(50, 50);
    Plane *plane2 = new Plane(10, 10);
    Plane *plane3 = new Plane(15, 15);
    plane->setLocation(glm::vec3(-3, -1, -3));
    plane->rotate(glm::radians(0.0f), glm::vec3(1,1,0));
    plane->setAmbient(glm::vec3(0,1,0));
    plane2->setLocation(glm::vec3(0, 1, 0));
    plane3->setLocation(glm::vec3(0.2, 0.5, -0.5));
    plane3->setAmbient(glm::vec3(0, 0, 1));
    plane->createGeometry();
    plane2->createGeometry();
    plane3->createGeometry();
    _planes.push_back(plane);
    _planes.push_back(plane2);
    _planes.push_back(plane3);

    Model model;
    

    // First pass
    this->paintGL();
    return true;
}

void GLContext::paintGL() {

    glClearColor(0.1, 0.1, 0.1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Render all meshes here
   
    try {

        // Set the VP matrix
        this->_VP = this->_projection * this->_camera;

        // Render all assets
        for (int i = 0; i < _planes.size(); i++) {
            _planes.at(i)->render(_VP, SDL_GetTicks(), this->_camera_location);
        }

        
    } catch (exception e) {
        cout << "Error render assets: " << e.what() << endl;
    }

    SDL_GL_SwapWindow(this->_main_window);

}

void GLContext::mainLoop() {

    int old_time = SDL_GetTicks();

    this->_looping = true;
    static float rotation = 0.0f;
    float mouse_pressed = false;
    int mouse_x(0), mouse_y(0), old_mouse_x(0), old_mouse_y(0);
    glm::vec4 h4 = glm::vec4(this->_horizontal_camera_vector.x, this->_horizontal_camera_vector.y, this->_horizontal_camera_vector.z, 1.0f);
    
    while (this->_looping) {

      SDL_GetMouseState(&mouse_x, &mouse_y);

        while (SDL_PollEvent(&_event) > 0) {

            if (_event.type == SDL_QUIT) {
                this->_looping = false;
            }

            /********************************************************************************
             * KEYBOARD EVENTS
             */
            if (_event.type == SDL_KEYDOWN) {

	      switch(_event.key.keysym.sym) {
	      case SDLK_ESCAPE:
		this->_looping = false;
		break;
	      case SDLK_i:
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;
	      case SDLK_o:
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	      case SDLK_LEFT:
		h4 = h4 * glm::rotate(glm::mat4(1.0f), glm::radians(1.0f), this->_up_camera_vector);
		this->_horizontal_camera_vector = glm::vec3(h4.x, h4.y, h4.z);
		this->_camera = glm::rotate(this->_camera, glm::radians(1.0f), this->_up_camera_vector);
		break;
	      case SDLK_RIGHT:
		h4 = h4 * glm::rotate(glm::mat4(1.0f), glm::radians(-1.0f), this->_up_camera_vector);
		this->_horizontal_camera_vector = glm::vec3(h4.x, h4.y, h4.z);
		this->_camera = glm::rotate(this->_camera, glm::radians(-1.0f), this->_up_camera_vector);
		break;
	      case SDLK_UP:                       
		this->_camera = glm::rotate(this->_camera, glm::radians(1.0f), this->_horizontal_camera_vector);
		break;
	      case SDLK_DOWN:
		this->_camera = glm::rotate(this->_camera, glm::radians(-1.0f), this->_horizontal_camera_vector);
		break;
	      case SDLK_F11:
		SDL_SetWindowFullscreen(this->_main_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
		this->_w = 1920; this->_h = 1080;
		_projection = glm::perspectiveFov(glm::radians(this->_fov), (float)this->_w, (float)this->_h, 0.1f, 1000.0f);    
		glViewport(0, 0, 1920, 1080);
		this->paintGL();
		break;
	      case SDLK_F12:
		SDL_SetWindowFullscreen(this->_main_window, 0);
		_projection = glm::perspectiveFov(glm::radians(this->_fov), (float)this->_w, (float)this->_h, 0.1f, 1000.0f);    
		glViewport(0, 0, 800, 600);
		break;
	      case SDLK_w:
		this->_camera = glm::translate(this->_camera, glm::vec3(-this->_eye_direction) / 50.0f);
		break;
	      case SDLK_s:
		this->_camera = glm::translate(this->_camera, glm::vec3(this->_eye_direction) / 50.0f);
		break;
	      case SDLK_a:
		this->_camera = glm::translate(this->_camera, glm::vec3(this->_horizontal_camera_vector) / 50.0f);
		break;
	      case SDLK_d:
		this->_camera = glm::translate(this->_camera, glm::vec3(-this->_horizontal_camera_vector) / 50.0f);
		break;
	      }
            }
	    
	    /********************************************************************************
	     * MOUSE EVENTS
	     */
	    if (_event.type == SDL_MOUSEBUTTONDOWN) {
	      mouse_pressed = true;
	      SDL_GetMouseState(&old_mouse_x, &old_mouse_y);
	    }

	    if (_event.type == SDL_MOUSEBUTTONUP) 
	      mouse_pressed = false;
	      
	    if (_event.type == SDL_MOUSEWHEEL) {
	      _projection = glm::perspectiveFov(glm::radians(this->_fov), (float)this->_w, (float)this->_h, 0.1f, 1000.0f);    
	      if (_event.wheel.y < 0) this->_fov += 0.5f;
	      if (_event.wheel.y > 0) this->_fov -= 0.5f;
	    }
	    
	    if (_event.type == SDL_MOUSEMOTION && mouse_pressed) {
	      
	      int deltax = mouse_x - old_mouse_x;
	      int deltay = mouse_y - old_mouse_y;

	      h4 = h4 * glm::rotate(glm::mat4(1.0f), glm::radians(static_cast<float>(deltax / 10.0f)), this->_up_camera_vector);
	      this->_horizontal_camera_vector = glm::vec3(h4.x, h4.y, h4.z);
	      this->_camera = glm::rotate(this->_camera, glm::radians(static_cast<float>(deltax / 10.0f)), this->_up_camera_vector);
	      this->_camera = glm::rotate(this->_camera, glm::radians(static_cast<float>(deltay / 10.0f)), this->_horizontal_camera_vector);

	      glm::vec4 eye4 = glm::vec4(this->_eye_direction.x, this->_eye_direction.y, this->_eye_direction.z, 1.0f);
	      eye4 = eye4 * glm::rotate(glm::mat4(1.0f), glm::radians(deltax / 10.0f), this->_up_camera_vector);
	      eye4 = eye4 * glm::rotate(glm::mat4(1.0f), glm::radians(deltay / 10.0f), this->_horizontal_camera_vector);
	      this->_eye_direction = glm::vec3(eye4.x, eye4.y, eye4.z);

	      old_mouse_x = mouse_x; old_mouse_y = mouse_y;
	      
	    }
	    
        }

        if (SDL_GetTicks() - old_time > 80) {
            old_time = SDL_GetTicks();
            this->paintGL();
        }
        
    }
}

glm::mat4 GLContext::getMVP() {
    return this->_VP;
}

