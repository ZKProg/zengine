#version 450 core

layout(location=0) in vec3 vertex;
layout(location=1) in vec3 normal;

out vec3 color_from_vertex;

uniform mat4 MVP;
uniform float time;
uniform vec3 ambient;
uniform vec3 camera;

void main (void) {

    // Light sources
    vec3 sun = vec3(0, -4, -2);

    // Specular ligtning
    vec3 lightToVertex = normalize(vertex - sun);
    vec3 vertexToCamera = normalize(camera - vertex);
    vec3 reflectionVector = reflect(lightToVertex, normal);
    float specular = pow(max(dot(reflectionVector, vertexToCamera), 0), 5);

    // Diffuse lightning
    float diffuse_factor = dot (normalize(normal), normalize(sun));
    float diffuse = abs(diffuse_factor);

    // Torch light (spot light located at camera position)
    float kc = 1;
    float kl = 1;
    float kq = 1;
    float distanceSpotToVertex = length(vertex - camera);

    float spotFactor = 1.0f / (kc + kl * distanceSpotToVertex + kq * pow(distanceSpotToVertex/5.0f, 4));


    //gl_Position = MVP * vec4(cos(time) * 0.9 + vertex.x, sin(time) * 0.9 + vertex.y, vertex.z, 1);
    gl_Position = MVP * vec4(vertex.x, vertex.y, vertex.z, 1);

    color_from_vertex = spotFactor * diffuse * ambient + 0.3 *  vec3(0.5, 0.5, 0) + specular * vec3(0.3,0.3,0.3);

}