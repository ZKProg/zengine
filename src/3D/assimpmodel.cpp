#include "../../include/3D/assimpmodel.h"

using namespace std;

AssimpModel::AssimpModel(const char *path_to_model) {

  this->_scene = this->_model_importer.ReadFile(path_to_model, aiProcess_GenUVCoords | aiProcess_Triangulate | aiProcess_GenUVCoords);

  if (!this->_scene || this->_scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !this->_scene->mRootNode) {

    cout << this->_model_importer.GetErrorString() << endl;
    return;
    
  }

  Mesh *mesh = 0;

  // Read the file and store the data
  for (unsigned int m = 0; m < this->_scene->mNumMeshes; m++) {

    mesh = new Mesh(this->_scene->mMeshes[m]);
    vector<glm::vec3> vertices;
    vector<glm::vec3> normals;
    vector<unsigned int> elements;
    vector<glm::vec2> uvs;

    // Elements
    for (unsigned int e = 0; e < this->_scene->mMeshes[m]->mNumFaces; e++) {

      elements.push_back(this->_scene->mMeshes[m]->mFaces[e].mIndices[0]);
      elements.push_back(this->_scene->mMeshes[m]->mFaces[e].mIndices[1]);
      elements.push_back(this->_scene->mMeshes[m]->mFaces[e].mIndices[2]);
      
    }

    // Vertices
    for (unsigned int v = 0; v < this->_scene->mMeshes[m]->mNumVertices; v++) {

      glm::vec3 current_vertex(this->_scene->mMeshes[m]->mVertices[v].x,
			       this->_scene->mMeshes[m]->mVertices[v].y,
			       this->_scene->mMeshes[m]->mVertices[v].z);

      vertices.push_back(current_vertex);

      // Texture coordinates? If so, store the UV coordinate of the current vertex.
      if (this->_scene->mMeshes[m]->mTextureCoords[0]) {

	glm::vec2 coord;
	coord.x = this->_scene->mMeshes[m]->mTextureCoords[0][v].x;
	coord.y = this->_scene->mMeshes[m]->mTextureCoords[0][v].y;

	cout << coord.x << ":" << coord.y << endl;
	
	uvs.push_back(coord);
      } else {
	uvs.push_back(glm::vec2(0,0));
      }
    }

    
    // Normals
    for (unsigned int n = 0; n < this->_scene->mMeshes[m]->mNumVertices; n++) {

      glm::vec3 current_normal(this->_scene->mMeshes[m]->mNormals[n].x,
			       this->_scene->mMeshes[m]->mNormals[n].y,
			       this->_scene->mMeshes[m]->mNormals[n].z);

      normals.push_back(current_normal);

    }

    // Materials
    if (this->_scene->mMeshes[m]->mMaterialIndex >= 0) {

      aiMaterial *material = this->_scene->mMaterials[this->_scene->mMeshes[m]->mMaterialIndex];
      aiString texture_path;
      material->GetTexture(aiTextureType_DIFFUSE, 0, &texture_path);
      
      string texture_file_path = (string)texture_path.C_Str();
      string texture_file_name = "models/" + texture_file_path.substr(texture_file_path.find_last_of('/') + 1, texture_file_path.size());

      cout << texture_file_name << endl;

      Texture texture("models/uvlayout.png");
      mesh->addTexture(texture);
      
    }
    
    mesh->setVertices(vertices);
    mesh->setNormals(normals);
    mesh->setElements(elements);
    mesh->setUvs(uvs);
    mesh->setShaders("shaders/cube.vert.glsl", "shaders/cube.frag.glsl");
    mesh->initBufferData();

    this->_meshes.push_back(mesh);
  }

}

AssimpModel::~AssimpModel() {


}

void AssimpModel::render(const glm::mat4 &VP, int tick, const glm::vec3 &camera_location) {

  for (int i = 0; i < this->_meshes.size(); i++) {
    this->_meshes.at(i)->render(VP, tick, camera_location);
  }

}
