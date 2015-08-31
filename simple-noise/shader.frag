#version 330

uniform float time;
out vec4 fragment;

float hash(uint n) {
  n += (n << 10u);
  n ^= (n >> 6u);
  n += (n << 3u);
  n ^= (n >> 11u);
  n += (n << 15u);
  n &= 0x007FFFFFu;
  n |= 0x3F800000u;
  float x = uintBitsToFloat(n);
  return x - 1.0;
}

void main() {
  float t = time * 100.0;
  float pixel = hash(uint(gl_FragCoord.x) ^ uint(gl_FragCoord.y) ^ uint(abs(t)));
  fragment = vec4(vec3(pixel), 1.0);
}
