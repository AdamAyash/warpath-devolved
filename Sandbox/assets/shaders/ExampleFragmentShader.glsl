#version 460 core

in vec2 oTexureCoordinates;
out vec4 oTextureColor;

uniform sampler2D oTexture0;
uniform vec3 oColor;

void main()
{    
    oTextureColor = vec4(texture(oTexture0, oTexureCoordinates));
} 