#include "Engine/ResourceManager.h"
#include "raylib.h"

namespace BB {
  // Instantiate static variables
  std::map<std::string, Texture2D> ResourceManager::Textures;
  std::vector<Object*> ResourceManager::Objects;
  std::map<std::string, std::shared_ptr<Scene>> ResourceManager::Scenes;
  std::map<std::string, Sound> ResourceManager::Sounds;

  Texture2D ResourceManager::LoadTexture(const char *file, std::string name){
    if(Textures[name].id <= 0){
      Textures[name] = ::LoadTexture(file);
    }
    return Textures[name];
  }


  Texture2D ResourceManager::GetTexture(std::string name){
    return Textures[name];
  }

  Sound ResourceManager::LoadSound(const char *file, std::string name){
    // if(Sounds[name]){
    Sounds[name] = ::LoadSound(file);
    // }
    return Sounds[name];
  }

  Sound ResourceManager::GetSound(std::string name){
    return Sounds[name];
  }

  void ResourceManager::AddObject(Object* object){
    Objects.emplace_back(object);
  }

  std::vector<Object*> ResourceManager::GetObjects(){
    return Objects;
  }

  void ResourceManager::Clear(){
    for(auto& texture: Textures){
      UnloadTexture(texture.second);
    }

    for(auto& sound : Sounds){
      UnloadSound(sound.second);
    }
  }
  
  
}
