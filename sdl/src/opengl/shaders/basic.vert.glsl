#version 330

in vec3 inPosition;

uniform vec3 translation_vec;

void main()
{
    gl_Position = vec4(inPosition + translation_vec, 1.0);

}
