#version 450 core

in vec3 color_from_vertex;
out vec3 color;

void main (void) {
    color = color_from_vertex;
}