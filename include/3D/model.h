#ifndef MODEL_H
#define MODEL_H

#include "mesh.h"

#include <assimp/mesh.h>
#include <assimp/scene.h>
#include <assimp/camera.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>

class Model : public Mesh {

public:
  Model();
  virtual ~Model();

  virtual void createGeometry();

protected:

  const aiScene *_scene;
  std::vector<Mesh> _meshes;
  Assimp::Importer _importer;


};

#endif MODEL_H
