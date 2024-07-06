#version 330 core

in vec2 TexCoord;
out vec4 FragColor;

uniform vec3 lightDir;
uniform sampler2D normalMap;
uniform samplerCube skybox;

void main()
{
    // Retrieve normal from normal map
    vec3 normal = texture(normalMap, TexCoord).rgb;
    normal = normalize(normal * 2.0 - 1.0);

    // Calculate view direction
    vec3 viewDir = normalize(-vec3(gl_FragCoord.xy, 1.0));

    // Calculate reflection vector
    vec3 reflectDir = reflect(-viewDir, normal);

    // Calculate diffuse lighting
    float diffuse = max(dot(normal, normalize(lightDir)), 0.0);

    // Calculate specular lighting
    vec3 halfwayDir = normalize(normalize(lightDir) + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), 64.0);

    // Basic water color
    vec3 baseColor = vec3(0.0, 0.3, 0.7);

    // Combine base color with diffuse and specular
    vec3 color = baseColor * diffuse + vec3(1.0) * spec;

    // Sample environment map for reflection
    vec3 envColor = texture(skybox, reflectDir).rgb;

    // Mix base color with reflection
    color = mix(color, envColor, 0.5);

    FragColor = vec4(color, 1.0);
}
