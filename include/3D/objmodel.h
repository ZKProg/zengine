#ifndef OBJ_MODEL_H
#define OBJ_MODEL_H

#include "mesh.h"
#include "objloader.h"

class ObjModel : public Mesh {

public:

  ObjModel(const char* path_to_obj_file);
  virtual ~ObjModel();

  virtual void createGeometry();

protected:

  ObjLoader *_obj_loader;

};

#endif // OBJ_MODEL_H
