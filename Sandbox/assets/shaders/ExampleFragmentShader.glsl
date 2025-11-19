#version 460 core

in vec2 oTextureCoordinatesOut;
out vec4 oTextureColor;

uniform sampler2D oTexture0;

void main()
{    
    oTextureColor = texture(oTexture0, oTextureCoordinatesOut);
} 