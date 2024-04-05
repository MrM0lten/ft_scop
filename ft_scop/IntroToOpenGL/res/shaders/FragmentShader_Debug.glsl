#version 330 core

out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    float r, g, b;
    r = (gl_PrimitiveID % 255) / 255.0f;
    g = ((gl_PrimitiveID / 255) % 255) / 255.0f;
    b = ((gl_PrimitiveID / (255 * 255)) % 255) / 255.0f;
    FragColor = vec4(r,g,b,1.0f);
}