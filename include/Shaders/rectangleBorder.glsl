R"(
#shader vertex
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
out vec2 position;
out float cameraZoomOut;

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
  
  position = (cameraZoom*origin - cameraPos);

  cameraZoomOut = cameraZoom;


};

#shader fragment
#version 330 core

out vec4 FragColor;

in vec4 ourColor;
in vec2 position;
in float cameraZoomOut;

void main()
{
  vec2 resolution = vec2(1440,720);
  vec2 st = gl_FragCoord.xy/resolution;
  vec3 color = vec3(0);

  //left and bottom outline
  float left = step(((position.x+1)/2.0)-(cameraZoomOut*.0105),st.x);
  float bottom = step(((position.y+1)/2.0)-(cameraZoomOut*.021),st.y);

  float pct = left * bottom;

  //top and right
  float right = step(1.0-((position.x+1)/2.0)-(cameraZoomOut*.0105),1.0-st.x);
  float top = step(1.0-((position.y+1)/2.0)-(cameraZoomOut*.021),1.0-st.y);

  pct *= right * top;

  //color = vec3(pct);

  if(pct == 1.0)
  {
    FragColor = ourColor;
  }
  else
  {
    FragColor = vec4(1,0,0,1);
  }

  //FragColor = vec4(color,1);

};

)"