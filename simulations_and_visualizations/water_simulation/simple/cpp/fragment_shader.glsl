#version 330 core

in vec2 TexCoord;
out vec4 FragColor;

uniform float time;
uniform vec2 resolution;

void main()
{
    vec2 uv = TexCoord;

    float wave = sin(uv.x * 10.0 + time * 4.0) * 0.1 + cos(uv.y * 10.0 + time * 4.0) * 0.1;
    wave *= 0.5;

    vec3 color = vec3(0.0, 0.3, 0.7) + vec3(wave);

    FragColor = vec4(color, 1.0);
}
