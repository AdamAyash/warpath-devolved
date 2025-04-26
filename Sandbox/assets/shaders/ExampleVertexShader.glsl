#version 460 core
layout (location = 0) in vec4 oVertex;

out vec2 oTexureCoordinates;

uniform mat4 oModelMatrix;
uniform mat4 oProjectionMatrix;

void main()
{
    oTexureCoordinates = oVertex.zw;
    gl_Position = oProjectionMatrix * oModelMatrix * vec4(oVertex.xy, 0.0, 1.0);
}