#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;
layout(location=2) in vec2 uvs;

uniform mat4 MVP;
uniform vec3 ambient;
uniform vec3 camera;

out vec3 normal_from_vertex;
out vec2 uvs_from_vertex;

void main (void) {

  normal_from_vertex = normal;
  uvs_from_vertex = uvs;

  gl_Position = MVP * vec4(position.xyz, 1);

}
