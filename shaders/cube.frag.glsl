#version 330 core

in vec3 normal_from_vertex;

out vec3 color;

void main (void) {

  vec3 sun = vec3(-3, -10, 5);
  vec3 light = -1 * sun;
  float diffuse = max(dot(normalize(normal_from_vertex), normalize(sun)), 0);
  float diffuselight = max(dot(normalize(normal_from_vertex), normalize(light)), 0);
  
  color = diffuse * vec3(0.5,0.5,0.5) + diffuselight * vec3(0.3, 0.2, 0.2) + 0.2;

}
