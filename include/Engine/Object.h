#pragma once
#include "Config.h"
#include "CommandListener.h"

namespace BB {
  class Object : public CommandListener{
  public:
    Object();
    virtual ~Object();
    virtual bool update(bool onGround);
    virtual void Draw();
    virtual Rectangle getBoundingBox();
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
