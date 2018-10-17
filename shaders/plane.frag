#version 450 core

out vec3 color;

in vec3 ambient_fv;
in vec3 camera_fv;
in vec3 current_vertex;
in vec3 current_normal;

void main (void) {

  // Light sources
  vec3 sun = vec3(0, -4, -2);

  // Specular ligtning
  vec3 lightToVertex = normalize(current_vertex - sun);
  vec3 vertexToCamera = normalize(camera_fv - current_vertex);
  vec3 reflectionVector = reflect(lightToVertex, current_normal);
  float specular = pow(max(dot(reflectionVector, vertexToCamera), 0), 2);

  // Diffuse lightning
  float diffuse_factor = dot (normalize(current_normal), normalize(sun));
  float diffuse = abs(diffuse_factor);

  // Torch light (spot light located at camera position)
  float kc = 1;
  float kl = 1;
  float kq = 1;
  float distanceSpotToVertex = length(current_vertex - camera_fv);

  float spotFactor = 1.0f / (kc + kl * distanceSpotToVertex + kq * pow(distanceSpotToVertex/2.0f, 10));

  color = 0.5 * ambient_fv * (spotFactor + diffuse + specular);

}
