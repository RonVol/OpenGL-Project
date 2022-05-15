#Define Vertex Shader

#version 460 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTex;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection*view*model* vec4(aPos.x, aPos.y, aPos.z, 1.0);
    TexCoord = aTex;
}

#Define Fragment Shader

#version 460 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D tex1;
uniform sampler2D tex2;

void main()
{
    FragColor = mix(texture(tex1, TexCoord), texture(tex2, TexCoord), 0.5);
}
