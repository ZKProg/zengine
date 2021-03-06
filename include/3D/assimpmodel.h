#ifndef MODEL_H
#define MODEL_H

#include "mesh.h"

class AssimpModel {

public:

  AssimpModel(const char *path_to_model);
  virtual ~AssimpModel();

  void render(const glm::mat4 &VP, int tick, const glm::vec3 &camera_location);
  
protected:

  Assimp::Importer _model_importer;
  const aiScene *_scene;
  std::vector<Mesh*> _meshes;


};


#endif // MODEL_H
