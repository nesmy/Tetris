#include "Scene.h"
#include "Object.h"
#include "Menu.h"
#include "ResourceManager.h"
#include "Setting.h"

namespace BB {

  Scene::Scene(){
    int sceneHeight = GetScreenHeight();
    groundYPos = (3 * sceneHeight) / 4;
    gravity = 1;
    exit = false;
  }

  Scene::~Scene(){
    freeResources();
  }

  void Scene::loadResources(){
  }

  void Scene::freeResources(){
    playerAvatar.reset();
    Objects.clear();
  }

  void Scene::start(){
  }

  std::shared_ptr<Scene> Scene::update(){

    // for(auto &object : ResourceManager::GetObjects()){
    //   Objects.emplace_back(object);
    // }
    for(auto &object : Objects){
      // object->Position.x += object->Velocity.x;
      // object->Position.y += object->Velocity.y;

      auto boundingRect = object->getBoundingBox();
      auto distToGround = groundYPos - (boundingRect.y + boundingRect.height);
      bool isOnGround = distToGround <= 0;

      if(isOnGround){
	// object->Velocity.y = 0;
	// object->Position.y += distToGround;
      } else {
	// object->Velocity.y += gravity;
      }

      object->update(isOnGround);
    }

    if(exit){
      exit = false;
      return std::make_unique<MenuScene>();
    }
    else {
      return nullptr;
    }
  }

  bool Scene::shouldQuit(){
    return false;
  }

  void Scene::Draw(){
    
    ClearBackground(BLACK);
    // for(auto &object : BB::ResourceManager::GetObjects()){
    //   object->Draw();
    // }
    if(Objects.size()){
      for(auto &object : Objects){
	object->Draw();
      }
    } else{
      // DrawText("This scene has no content. Add some objects, or override Scene::Draw()", 20, 20, 20, RED);
    }
  }

  void Scene::goUp(){
    if(playerAvatar){
      playerAvatar->goUp();
    }
  }

  void Scene::goLeft(){
    if(playerAvatar){
      playerAvatar->goLeft();
    }
  }

  void Scene::goRight(){
    if(playerAvatar){
      playerAvatar->goRight();
    }
  }

  void Scene::goDown(){
    if(playerAvatar){
      playerAvatar->goDown();
    }
  }

  void Scene::goNowhere(){
    if(playerAvatar){
      playerAvatar->goNowhere();
    }
  }

  void Scene::doInteractWith(){
    if(playerAvatar){
      playerAvatar->doInteractWith();
    }
  }

  void Scene::doExit(){
    exit = true;
  }
  
}
