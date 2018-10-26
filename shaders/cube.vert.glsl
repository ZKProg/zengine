#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;

uniform mat4 MVP;
out vec3 normal_from_vertex;

void main (void) {

  normal_from_vertex = normal;
  
  gl_Position = MVP * vec4(position.xyz, 1.0f);

}
