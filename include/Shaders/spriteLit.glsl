#pragma once

const char * spriteLit = 

R"(#shader vertex
#version 330 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec4 aColor;
layout(location = 2) in vec2 aTexCoord;

uniform vec2 cameraPos = vec2(0, 0);
uniform float cameraZoom = 1;
uniform float rotation = 0;
uniform vec2 origin = vec2(0, 0);
uniform float aspectRatio = 1;

out vec4 ourColor;
out vec2 TexCoord;
out float rotationAngle;

out vec3 FragPos;

void main()
{

  vec2 vertices = cameraZoom * aPos - cameraPos;

  if (rotation != 0)
  {
    float angle = radians(rotation);
      mat2 rotationMatrix = mat2(cos(angle), aspectRatio * sin(angle), -sin(angle) / aspectRatio, cos(angle));

    vertices = vertices - (cameraZoom * origin - cameraPos);
    vertices = rotationMatrix * vertices;
    vertices = vertices + (cameraZoom * origin - cameraPos);
  }

  ourColor = aColor;
  gl_Position = vec4(vertices, 1.0, 1.0);

  TexCoord = aTexCoord;

  rotationAngle = rotation;

  FragPos = vec3(vertices.x*aspectRatio,vertices.y,1.0);

}

#shader fragment
#version 330 core

out vec4 FragColor;

in vec4 ourColor;
in vec2 TexCoord;
in vec3 FragPos;
in float rotationAngle;

uniform sampler2D ourTexture;
uniform vec3 lightPosition = vec3(0,0,0);
uniform float ambientIntensity = 1.0;

uniform float constantLight = 1.0;
uniform float linearLight = 1.0;
uniform float quadLight = 1.0;
uniform float diffuseIntensity = 1.0;
uniform float lightSize = 1.0;

void main()
{
  vec3 lightColor = vec3(1,1,1);

  vec3 norm = normalize(-FragPos);
  vec3 lightDir = normalize(lightPosition - FragPos);

  float diff = max(dot(norm, lightDir),0.0);

  vec3 diffuse = diff * lightColor;

  float dist = length(lightPosition - FragPos);

  float attenuation = 1.0 / (constantLight + linearLight * dist + quadLight * (dist * dist));

  vec3 ambient = vec3(ambientIntensity);

  //ambient *= attenuation;
  diffuse *= attenuation*diffuseIntensity;

  if(dist > lightSize)
  {
    //diffuse = vec3(0.0);
  }

  vec3 lightResult = (ambient + diffuse) * ourColor.xyz;

  FragColor = texture(ourTexture, TexCoord) * vec4(lightResult,1.0);

}

)";