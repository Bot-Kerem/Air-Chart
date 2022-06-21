#version 460 core

layout (location = 0) in vec2 inPosition;
layout (location = 1) in float inOpen;
layout (location = 2) in float inClose;
layout (location = 3) in int inOrder;
layout (location = 4) in int inColor;

uniform float spacing;
uniform float width;
uniform float height;
uniform float offset;

uniform mat3 ascale;
uniform vec3 atranslate;

uniform vec3 down;
uniform vec3 up;

out vec3 outColor;

vec3 colors[2] = 
{
    down, up
};

void main()
{   
    outColor = colors[inColor];
    vec2 pos = vec2(((inPosition.x*width) + (width+spacing)*inOrder)+offset, ((inPosition.y*(inOpen-inClose))+inClose)*height);

    gl_Position = vec4(vec3(pos, 0.0f)+atranslate, 1.0f);
}