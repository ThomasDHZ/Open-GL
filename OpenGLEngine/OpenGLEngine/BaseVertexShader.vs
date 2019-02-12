#version 330 core
layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec3 vNormalMapping;
layout (location = 2) in vec2 vTextureCoordinates;
layout (location = 3) in vec2 vTangant;
layout (location = 4) in vec2 vBitangant;
layout (location = 5) in vec2 vColor;

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    FragPos = vec3(model * vec4(vPosition, 1.0));
    Normal = mat3(transpose(inverse(model))) * vNormalMapping;  
    TexCoords = vTextureCoordinates;
    
    gl_Position = projection * view * vec4(FragPos, 1.0);
}