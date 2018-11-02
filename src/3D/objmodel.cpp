#include "../../include/3D/objmodel.h"

using namespace std;

ObjModel::ObjModel(const char* path_to_obj_file) :
  _obj_loader(nullptr),
  Mesh()
{

  this->_obj_loader = new ObjLoader(path_to_obj_file);
  this->createGeometry();

}


ObjModel::~ObjModel() {


}


void ObjModel::createGeometry() {

  this->setVertices(this->_obj_loader->getVertices());
  this->setNormals(this->_obj_loader->getNormals());
  this->setElements(this->_obj_loader->getElements());
  this->setUvs(this->_obj_loader->getUvs());

  this->setShaders("shaders/cube.vert.glsl", "shaders/cube.frag.glsl");
  
  this->initBufferData();

}
