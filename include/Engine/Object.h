#pragma once
#include "Config.h"
#include "CommandListener.h"

namespace BB {
  class Object : public CommandListener{
  public:
    Object(){}
    virtual ~Object(){}
    virtual bool update(bool onGround){return true;}
    virtual void Draw(){}
    virtual Rectangle getBoundingBox(){
      Rectangle result = {Position.x, Position.y, (float)Texture.width, (float)Texture.height};
      return result;
    }
    virtual void goUp(){
    }
    // {
    //   DrawTextureEx(Texture, Position, Rotation, Scale, WHITE);
    // }
    Vector2 &GetPosition() { return Position;}
    Texture2D &GetTexture() { return Texture;}
  public:
    Texture2D Texture;
    Vector2 Position;
    Vector2 Velocity;
    float Rotation;
    float Scale;
  };
  
    }
