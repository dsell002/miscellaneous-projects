#version 330 core

in vec2 TexCoord;
out vec4 FragColor;

uniform vec3 lightDir;

void main()
{
    // Calculate normal based on wave direction
    vec3 normal = normalize(vec3(-0.1 * cos(TexCoord.x * 20.0), -0.1 * sin(TexCoord.y * 20.0), 1.0));

    // Calculate diffuse lighting
    float diffuse = max(dot(normal, normalize(lightDir)), 0.0);

    // Basic water color with lighting
    vec3 baseColor = vec3(0.0, 0.3, 0.7);
    vec3 color = baseColor * diffuse;

    FragColor = vec4(color, 1.0);
}
