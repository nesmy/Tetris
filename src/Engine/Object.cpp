#include "Object.h"
#include "ResourceManager.h"
#include "raylib.h"

namespace BB {

  Object::Object(){
    // ResourceManager::AddObject(this);
  }

  Object::~Object(){
  }

  bool Object::update(bool onGround){
    return true;
  }

  void Object::Draw(){
  }

  Rectangle Object::getBoundingBox(){

    Rectangle result = {Position.x, Position.y, (float)Texture.width, (float)Texture.height};
    return result;
  }
}
