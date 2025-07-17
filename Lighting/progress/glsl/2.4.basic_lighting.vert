#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 Gouraud;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;

void main()
{
// Gouraud Shading is Phong shading that is implement in the vertex shader
	vec3 FragPos = vec3(model * vec4(aPos, 1.0));
	vec3 Normal = mat3(transpose(inverse(model))) * aNormal;  

	    // ambient
    float ambientStrength = 0.1f;
    //vec3 ambient = ambientStrength * lightColor * objectColor; 
    vec3 ambient = ambientStrength * lightColor; 

    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    //vec3 diffuse = diff * lightColor * objectColor;
    vec3 diffuse = diff * lightColor;
            

    // specular 
    float specularStrength = 1.5f;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float shininess = 32.0f;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = specularStrength * spec * lightColor;  

    vec3 gouraud = (ambient + diffuse + specular);

    Gouraud = gouraud;
	gl_Position = projection * view * model * vec4(aPos, 1.0);
}