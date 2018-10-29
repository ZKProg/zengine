#include "../../include/3D/objloader.h"

using namespace std;

ObjLoader::ObjLoader(const char *obj_file_path) {

  this->_obj_file.open(obj_file_path);

  if (!this->_obj_file.is_open()) {

    cout << "The model " << obj_file_path << " could not be opened." << endl;
    return;

  }

  // Load content --------------------------------------------------------
  string current;
  
  while (getline(this->_obj_file, current)) {

    istringstream ss(current);
    string first;

    ss >> first;
    // Comments. We do nothing.
    if (first.at(0) == '#') continue;

    // VERTEX ------------------------------------------------------------
    if (current.at(0) == 'v' && current.at(1) == ' ') {

      glm::vec3 temp;
	
      // We have to parse one vertex coordinates
      for (int j = 0; j < 3; j++) {

	string value;
	ss >> value;
	if (j == 0) temp.x = stof(value);
	if (j == 1) temp.y = stof(value);
	if (j == 2) temp.z = stof(value);

      }

      this->_vertices.push_back(temp);	

    }

    // NORMAL --------------------------------------------------------------
    if (current.at(0) == 'v' && current.at(1) == 'n') {

      glm::vec3 temp;
      
      for (int j = 0; j < 3; j++) {

	string value;
	ss >> value;
	
	if (j == 0) temp.x = stof(value);
	if (j == 1) temp.y = stof(value);
	if (j == 2) temp.z = stof(value);

      }

      this->_normals.push_back(temp);	

    }

    // ELEMENTS --------------------------------------------------------------
    if (current.at(0) == 'f' && current.at(1) == ' ') {

      for (int j = 0; j < 3; j++) {

	string value;
	ss >> value;

	string part_that_interests_us = value.substr(0, value.find_first_of('/')); 

	this->_elements.push_back((unsigned int)stoi(part_that_interests_us));
	
      }

    }

    // UV COORD --------------------------------------------------------------
    if (current.at(0) == 'v' && current.at(1) == 't') {

      glm::vec2 temp;

      for (int j = 0; j < 2; j++) {

	string value;
	ss >> value;

	if (j == 0)  temp.x = stof(value);
        if (j == 1)  temp.y = stof(value);
    
      }

      this->_uvs.push_back(temp);

    }
    
  } // End while getline ------------------------------------------------------

}


ObjLoader::~ObjLoader() {


}


vector<glm::vec3> ObjLoader::getVertices() {
  return this->_vertices;
}

vector<glm::vec3> ObjLoader::getNormals() {
  return this->_normals;
}

vector<unsigned int> ObjLoader::getElements() {
  return this->_elements;
}

vector<glm::vec2> ObjLoader::getUvs() {
  return this->_uvs;
}
