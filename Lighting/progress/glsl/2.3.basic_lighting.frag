#version 330 core
out vec4 FragColor;

in vec3 FragPos; 
in vec3 Normal;
in vec3 LightPos;


uniform vec3 objectColor;
uniform vec3 lightColor;

void main()
{
    // ambient
    float ambientStrength = 0.1f;
    //vec3 ambient = ambientStrength * lightColor * objectColor; 
    vec3 ambient = ambientStrength * lightColor; 

    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(LightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    //vec3 diffuse = diff * lightColor * objectColor;
    vec3 diffuse = diff * lightColor;
            

    // specular 
    float specularStrength = 1.5f;
    vec3 viewDir = normalize(-FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float shininess = 32.0f;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = specularStrength * spec * lightColor;  

    vec3 phong = (ambient + diffuse + specular) * objectColor;

    FragColor = vec4(phong, 1.0);
}