#version 450 core

layout(location=0) in vec3 vertex;
layout(location=1) in vec3 normal;

uniform mat4 MVP;
uniform float time;
uniform vec3 ambient;
uniform vec3 camera;

out vec3 ambient_fv;
out vec3 camera_fv;
out vec3 current_vertex;
out vec3 current_normal;

void main (void) {

  ambient_fv = ambient;
  camera_fv = camera;
  current_vertex = vertex;
  current_normal = normal;

  gl_Position = MVP * vec4(vertex.x, vertex.y, vertex.z, 1);

  

}
