uniform vec2 resolution;
uniform vec2 mousePosition;

void main() {
  vec2 position = gl_FragCoord.xy / resolution.xy;
  vec2 mousePosScaled = mousePosition.xy / resolution.xy;
  gl_FragColor.r = abs(position.x - mousePosScaled.x);
  gl_FragColor.g = abs(position.y - mousePosScaled.y);
  gl_FragColor.b = 1.0 - abs(position.x - mousePosScaled.x);
  gl_FragColor.a = 1.0;
}

