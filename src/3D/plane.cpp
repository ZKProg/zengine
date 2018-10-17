#include "../../include/3D/plane.h"

using namespace std;

Plane::Plane(float w, float h, float step) :
    _w(h), _h(h), _step(step), Mesh()
{

    this->_model = glm::mat4(1.0f);
    this->_location = glm::vec3(0, 0, 0);
    this->_ambient = glm::vec3(1, 0, 0);

    this->_shader = new Shader("./shaders/plane.vert", "./shaders/plane.frag");
    this->_program_id = this->_shader->getProgramID();

    glCreateBuffers(1, &_vbo);
    glCreateBuffers(1, &_nbo);

}

Plane::~Plane() {

}
    
void Plane::createGeometry() {

    srand(time(0));

    for (int h = 0; h < this->_h; h++) {
        for (int w = 0; w < this->_w; w++) {

            // Dev: Creates a randomly generated noise for height values
            float height = (rand() % 10) / 20.0f;


            glm::vec3 temp(
                (float)w * _step + this->_location.x,
                height + this->_location.y,
                (float)h * _step + this->_location.z
             );

            _vertex_bag.push_back(temp);

        }
    }

    int squares_along_width = this->_w - 1;
    int squares_along_height = this->_h - 1;

    for (int h = 0; h < squares_along_height; h++) {
        for (int w = 0; w < squares_along_width; w++) {

            // Deal with a square (2 triangles)
            int index_one = h * this->_w + w;
            int index_two = index_one + 1;
            int index_three = index_one + this->_w;
            int index_four = h * this->_w + w + 1;
            int index_five = index_four + (this->_w - 1);
            int index_six = index_five + 1;

            
            // First triangle
            this->_vertices.push_back(_vertex_bag.at(index_one));
            this->_vertices.push_back(_vertex_bag.at(index_two));
            this->_vertices.push_back(_vertex_bag.at(index_three));

            // Second triangle
            this->_vertices.push_back(_vertex_bag.at(index_four));
            this->_vertices.push_back(_vertex_bag.at(index_five));
            this->_vertices.push_back(_vertex_bag.at(index_six));


        }
    }

    // Compute normals
    for (int n = 0; n < this->_vertices.size(); n += 3) {

        glm::vec3 edge_one = this->_vertices.at(n) - this->_vertices.at(n + 1);
        glm::vec3 edge_two = this->_vertices.at(n) - this->_vertices.at(n + 2);

        glm::vec3 current_triangle_normal = glm::cross(edge_one, edge_two);

        // Store the normal as three vertices gets the same normal
        for (int i = 0; i < 3; i++) this->_normals.push_back(current_triangle_normal);

    }

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->_vertices.size() * 3, reinterpret_cast<GLfloat*>(this->_vertices.data()), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, _nbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->_normals.size() * 3, reinterpret_cast<GLfloat*>(this->_normals.data()), GL_STATIC_DRAW);

}

