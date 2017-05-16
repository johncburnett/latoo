#version 330
#pragma include "util.glsl"

uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 textureMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform vec4 globalColor;

uniform float scale;

layout (location = 0) in vec3 inPosition;

out vec4 positionVarying;

void main() {
    positionVarying = vec4(inPosition.x * scale, inPosition.y * scale, inPosition.z * scale, 1.0);
    gl_Position = modelViewProjectionMatrix * positionVarying;
}