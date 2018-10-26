#include "../../include/3D/model.h"

using namespace std;

Model::Model(const char *path_to_model) {

  this->_scene = this->_model_importer.ReadFile(path_to_model, aiProcess_Triangulate | aiProcess_OptimizeMeshes);

  if (!this->_scene || this->_scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !this->_scene->mRootNode) {

    cout << this->_model_importer.GetErrorString() << endl;
    return;
    
  }

  // Read the file and store the data
  for (unsigned int m = 0; m < this->_scene->mNumMeshes; m++) {

    Mesh *mesh = new Mesh(this->_scene->mMeshes[m]);
    vector<glm::vec3> vertices;
    vector<glm::vec3> normals;
    vector<unsigned int> elements;
  
    
    for (unsigned int e = 0; e < this->_scene->mMeshes[m]->mNumFaces; e++) {

      elements.push_back(this->_scene->mMeshes[m]->mFaces[e].mIndices[0]);
      elements.push_back(this->_scene->mMeshes[m]->mFaces[e].mIndices[1]);
      elements.push_back(this->_scene->mMeshes[m]->mFaces[e].mIndices[2]);
      
    }

    for (unsigned int v = 0; v < this->_scene->mMeshes[m]->mNumVertices; v++) {

      glm::vec3 current_vertex(this->_scene->mMeshes[m]->mVertices[v].x,
			       this->_scene->mMeshes[m]->mVertices[v].y,
			       this->_scene->mMeshes[m]->mVertices[v].z);

      vertices.push_back(current_vertex);
    }

    for (unsigned int n = 0; n < this->_scene->mMeshes[m]->mNumVertices; n++) {

      glm::vec3 current_normal(this->_scene->mMeshes[m]->mNormals[n].x,
			       this->_scene->mMeshes[m]->mNormals[n].y,
			       this->_scene->mMeshes[m]->mNormals[n].z);

      normals.push_back(current_normal);
    }

    mesh->setVertices(vertices);
    mesh->setNormals(normals);
    mesh->setElements(elements);
    mesh->setShaders("shaders/cube.vert.glsl", "shaders/cube.frag.glsl");
mesh->initBufferData();

    this->_meshes.push_back(mesh);

  }

}

Model::~Model() {


}

void Model::render(const glm::mat4 &VP, int tick, const glm::vec3 &camera_location) {

  for (int i = 0; i < this->_meshes.size(); i++) {
    this->_meshes.at(i)->render(VP, tick, camera_location);
  }

}
