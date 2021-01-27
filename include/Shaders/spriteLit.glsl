R"(
#shader vertex
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

  FragPos = vec3(vertices.x,vertices.y/(aspectRatio),1.0);

}

#shader fragment
#version 330 core

out vec4 FragColor;

in vec4 ourColor;
in vec2 TexCoord;
in vec3 FragPos;
in float rotationAngle;

uniform float numLights = 0;
uniform vec2 lights[1];

uniform sampler2D ourTexture;
uniform float ambientIntensity = 1.0;

uniform float constantLight = 1.0;
uniform float linearLight = 1.0;
uniform float quadLight = 1.0;
uniform float diffuseIntensity = 1.0;
uniform float lightSize = 1.0;
uniform float blur = 1.0;

void main()
{
  vec3 lightColor = vec3(1,1,1);
  vec3 lightResult = vec3(0);

  vec3 norm = normalize(-FragPos);

  for(int i = 0; i < lights.length(); i++)
  {

    vec3 lightDir = normalize(vec3(lights[i].x,lights[i].y,0) - FragPos);

    float diff = max(dot(norm, lightDir),0.0);

    vec3 diffuse = diff * lightColor;

    float dist = length(vec3(lights[i].x,lights[i].y,0) - FragPos);

    float attenuation = 1.0 / (constantLight + linearLight * dist + quadLight * (dist * dist));

    vec3 ambient = vec3(ambientIntensity);

    //ambient *= attenuation;
    diffuse *= attenuation*diffuseIntensity;

    if(dist > lightSize)
    {
      diffuse += vec3(-(1.0/blur)*(dist-lightSize)*(dist-lightSize));

      if(diffuse.x <0)
        diffuse.x = 0;

      if(diffuse.y <0)
        diffuse.y = 0;

      if(diffuse.z <0)
        diffuse.z = 0;

    }

    lightResult += (ambient + diffuse) * ourColor.xyz;
  }

  FragColor = texture(ourTexture, TexCoord) * vec4(lightResult,1.0);

}
)"