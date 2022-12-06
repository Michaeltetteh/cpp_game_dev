#version 330

in vec3 inPosition;

uniform mat4 uWorldTransform;
uniform mat4 uViewProjection;

void main()
{
    vec4 pos = vec4(inPosition ,1.0f); //object space
    gl_Position = pos * uWorldTransform * uViewProjection; //object -> world space

}
