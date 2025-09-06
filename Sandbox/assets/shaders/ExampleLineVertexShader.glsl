#version 460 core

layout (location = 0) in vec2 oVertex;

void main()
{
    gl_Position = vec4(oVertex.xy, 0.0, 1.0);
}