#include "../../include/3D/model.h"

using namespace std;

Model::Model() : Mesh(), _scene(nullptr) {

    this->_scene = this->_importer.ReadFile("./models/cube.obj",
        aiProcess_Triangulate
    );

    cout << this->_scene->mNumMeshes << endl;

}


Model::~Model() {
    
}
