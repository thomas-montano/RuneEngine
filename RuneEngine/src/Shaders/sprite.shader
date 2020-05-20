#shader vertex
#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform vec4 cameraPos = vec4(0,0,0,0);

out vec4 ourColor;
out vec2 TexCoord;

void main()
{
    gl_Position = vec4(aPos,1.0, 1.0) + cameraPos;
    ourColor = aColor;
    TexCoord = aTexCoord;
}

#shader fragment
#version 330 core

out vec4 FragColor;

in vec4 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture, TexCoord) * ourColor;
}
