#version 330 core
out vec4 FragColor;

struct Material {
    // --- SAMPLER2D = TEXTURE UNIT INDEX ---
    // These aren't textures themselves, but INTEGERS pointing to texture units
    // (e.g., 0 for GL_TEXTURE0, 1 for GL_TEXTURE1)
    sampler2D diffuse;  // Will sample from whatever texture is bound to unit X (set via setInt("material.diffuse", X  // Base color (wood/metal)
    sampler2D specular; // Same principle - unit Y set via setInt("material.specular", Y) // Shininess map
    // --- REGULAR UNIFORMS = ACTUAL VALUES ---
    float shininess;    // This is a direct float value (set via setFloat("material.shininess", 64.0)) // Overall glossiness
}; 

struct Light {
    // All these are direct vector values
    vec3 direction;  // Set via setVec3("light.position", x,y,z)
    vec3 ambient;   // setVec3("light.ambient", r,g,b)
    vec3 diffuse;   // setVec3("light.diffuse", r,g,b)
    vec3 specular;  // setVec3("light.specular", r,g,b)
};

in vec3 FragPos;  
in vec3 Normal;  
in vec2 TexCoords;
  
uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    // ambient
    vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(-light.direction);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;  
    
    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * texture(material.specular, TexCoords).rgb;  


    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
} 
/*
sampler2D is just a reference to a texture unit (like a TV channel number)
texture() does the actual work of:
    Filtering (bilinear/etc.)
    Mipmap selection
    Coordinate wrapping

texture():
    .rgb	vec3	Extracts red, green, blue channels (ignores alpha if present)
    .rg	    vec2	Extracts only red and green channels
    .r	    float	Extracts only the red channel
    .rrr	vec3	Creates a vec3 with the red value repeated 3 times (e.g., grayscale)
    .rgba	vec4	Explicitly extracts all channels (useful for reordering, e.g., .bgra)

*/