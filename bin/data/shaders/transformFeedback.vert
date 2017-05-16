#version 330

#pragma include "util.glsl"
//#pragma include "noise.glsl"

layout (location = 0) in vec3 inPosition;

out vec3 outPosition;

uniform float a;
uniform float b;
uniform float c;
uniform float d;

vec3 latoo(vec3 pos) {
    vec3 posn;
    posn.x = sin(b*pos.y) + (c * sin(b*pos.x));
    posn.y = sin(a*pos.x) + (d * sin(a*pos.y));
    posn.z = sin(a*pos.y) + (b * sin(a*pos.x));
    return posn;
}

vec3 latoo2(vec3 pos) {
    vec3 posn;
    posn.x = sin(b*pos.y) + (c * sin(b*pos.x)) + sin(d * sin(b*pos.z));
    posn.y = sin(a*pos.x) + (d * sin(a*pos.y)) + sin(c * sin(a*pos.z));
    posn.z = sin(a*pos.z) + (c * sin(b*pos.x)) + sin(d * sin(a*pos.y));
    return posn;
}

void main() {
    outPosition = latoo(inPosition);
}
