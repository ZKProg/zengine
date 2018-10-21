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

void Model::createGeometry() {

  glBindBuffer(1, this->_vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->_scene->mMeshes[0]->mNumVertices, this->_scene->mMeshes[0]->mVertices, GL_STATIC_DRAW);

}
