#version 460 core

layout (location = 0) in vec2 inPosition;

uniform mat3 scale;
uniform vec3 translate;

uniform mat3 ascale;
uniform vec3 atranslate;

void main()
{   
    const mat3 rscale = scale * ascale;
    const vec3 rtranslate = translate + atranslate;

    gl_Position = vec4((vec3(inPosition, 0.0f)*rscale)+rtranslate, 1.0f);
}