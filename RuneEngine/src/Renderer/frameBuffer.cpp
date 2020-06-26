#include "frameBuffer.h"
#include <gameApplication.h>
#include <iostream>
#include <GL\glew.h>
#include <gl\GLU.h>

rune::FrameBuffer::FrameBuffer()
  : bufferID(0), colorAttachment(0), width(0), height(0)
{
  invalidate();
}

rune::FrameBuffer::~FrameBuffer()
{
  glDeleteFramebuffers(1,&bufferID);
}

void rune::FrameBuffer::setSize(rune::Vec2 newSize)
{
  width = newSize.x;
  height = newSize.y;
  invalidate();
}

void rune::FrameBuffer::invalidate()
{
  if (bufferID)
  {
    glDeleteFramebuffers(1, &bufferID);
    glDeleteTextures(1, &colorAttachment);
  }

  glGenFramebuffers(1, &bufferID);
  glBindFramebuffer(GL_FRAMEBUFFER, bufferID);

  glGenTextures(1, &colorAttachment);
  glBindTexture(GL_TEXTURE_2D, colorAttachment);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 800, 600, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorAttachment, 0);

  if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
  {
  
    std::cout << "Frame buffer error!" << std::endl;
  
  }

  glBindFramebuffer(GL_FRAMEBUFFER,0);
}

void rune::FrameBuffer::bind()
{
  glBindFramebuffer(GL_FRAMEBUFFER, bufferID);
}

void rune::FrameBuffer::unbind()
{
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

unsigned int rune::FrameBuffer::getColorBuffer()
{
  return colorAttachment;
}
