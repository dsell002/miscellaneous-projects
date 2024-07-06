#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform float time;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    vec3 pos = aPos;

    // Use Perlin noise or a more complex wave function for better realism
    float wave1 = sin(pos.x * 10.0 + time * 4.0) * 0.05;
    float wave2 = cos(pos.y * 15.0 + time * 2.5) * 0.05;
    float wave3 = sin(pos.x * 20.0 + pos.y * 20.0 + time * 3.0) * 0.03;
    
    pos.z += wave1 + wave2 + wave3;

    gl_Position = projection * view * vec4(pos, 1.0);
    TexCoord = aTexCoord;
}
