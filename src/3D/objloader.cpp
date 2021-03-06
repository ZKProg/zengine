#include "../../include/3D/objloader.h"

using namespace std;

ObjLoader::ObjLoader(const char *obj_file_path) {

  // We push a "null" vertices to fit the opengl indexing scheme (starting at 1 instead of 0)
  // this->_vertices.push_back(glm::vec3(0,0,0));
  //this->_normals.push_back(glm::vec3(0,0,0));
  
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

    // UV COORD --------------------------------------------------------------
    if (current.at(0) == 'v' && current.at(1) == 't') {

      glm::vec2 temp;

      for (int j = 0; j < 2; j++) {

    	string value;
    	ss >> value;

    	if (j == 0)  temp.x = stof(value);
        if (j == 1)  temp.y = stof(value);
    
      }

      this->_uvs_bag.push_back(temp);

    }

    // VERTICES BAG---------------------------------------------------------
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

      this->_vertices_bag.push_back(temp);	

    }

    // NORMALS BAG ---------------------------------------------------------
    if (current.at(0) == 'v' && current.at(1) == 'n') {

      glm::vec3 temp;
      
      for (int j = 0; j < 3; j++) {

	string value;
	ss >> value;
	
	if (j == 0) temp.x = stof(value);
	if (j == 1) temp.y = stof(value);
	if (j == 2) temp.z = stof(value);

      }

      this->_normals_bag.push_back(temp);	

    }

    // ELEMENTS --------------------------------------------------------------

    map<pair<int,int>,int>::iterator it;
    static int element_index = 0;
    
    if (current.at(0) == 'f' && current.at(1) == ' ') {

      for (int j = 0; j < 3; j++) {
	
	string value;
	ss >> value;

	string vertex_index_string = value.substr(0, value.find_first_of('/')); 
	string normal_index_string = value.substr(value.find_last_of('/') + 1, value.size());

	int vertex_index = stoi(vertex_index_string) - 1;
	int normal_index = stoi(normal_index_string) - 1;

	it = this->_vertex_normal_pairs.find(make_pair(vertex_index, normal_index));

	if (it == this->_vertex_normal_pairs.end()) {

	  // The current pair was not found
	  this->_vertex_normal_pairs[make_pair(vertex_index, normal_index)] = element_index;

	  this->_vertices.push_back(this->_vertices_bag.at(vertex_index));
	  this->_normals.push_back(this->_normals_bag.at(normal_index));
	  this->_elements.push_back(element_index);

	  element_index++;
	  
	} else {

	  this->_elements.push_back(it->second);

	}
	  
      }
    }

  } // End while getline ------------------------------------------------------

  this->_vertex_normal_pairs.clear();
  this->_normals_bag.clear();
  this->_vertices_bag.clear();
  this->_uvs_bag.clear();
  
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

 void ObjLoader::displayVector(const glm::vec3 &vector) {
   cout << vector.x << ":" << vector.y << ":" << vector.z << endl;
 }
