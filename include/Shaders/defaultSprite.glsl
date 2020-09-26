#pragma once

const char * defaultSprite = 

R"(#shader vertex
#version 330 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec4 aColor;
layout(location = 2) in vec2 aTexCoord;

uniform vec2 cameraPos = vec2(0, 0);
uniform float cameraZoom = 1;
uniform float rotation = 0;
uniform vec2 origin = vec2(0,0);
uniform float aspectRatio = 1;

out vec4 ourColor;
out vec2 TexCoord;

void main()
{

  vec2 vertices = cameraZoom*aPos - cameraPos;

  if(rotation != 0)
  {
    float angle = radians(rotation);
    mat2 rotationMatrix = mat2(cos(angle), aspectRatio*sin(angle), -sin(angle)/aspectRatio, cos(angle));
        
    vertices = vertices - (cameraZoom*origin - cameraPos);
    vertices = rotationMatrix * vertices;
    vertices = vertices + (cameraZoom*origin - cameraPos); 
  }

  ourColor = aColor;
  gl_Position = vec4(vertices,0,1);

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

)";