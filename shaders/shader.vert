#version 460 core

layout (location = 0) in vec2 inPosition;
layout (location = 1) in float inData;
layout (location = 2) in int inOrder;

uniform float spacing;
uniform float width;
uniform float height;

uniform mat3 ascale;
uniform vec3 atranslate;

void main()
{   
    vec2 pos = vec2((inPosition.x*width) + (width+spacing)*inOrder, (inPosition.y*inData)*height);

    gl_Position = vec4(vec3(pos, 0.0f)+atranslate, 1.0f);
}