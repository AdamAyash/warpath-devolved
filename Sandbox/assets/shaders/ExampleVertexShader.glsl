#version 460 core
layout (location = 0) in vec2 oPosition;
layout (location = 1) in vec2 oTextureCoordinates;

out vec2 oTextureCoordinatesOut;

uniform mat4 oProjectionMaxtrix;

void main()
{
    gl_Position = oProjectionMaxtrix * vec4(oPosition.xy, 0.0, 1.0);
    oTextureCoordinatesOut = oTextureCoordinates;
}