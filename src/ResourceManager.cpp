#include "Engine/ResourceManager.h"
#include "raylib.h"

namespace BB {
  // Instantiate static variables
  std::map<std::string, Texture2D> ResourceManager::Textures;
  std::map<std::string, Font> ResourceManager::Fonts;
  std::vector<Object*> ResourceManager::Objects;
  std::map<std::string, std::shared_ptr<Scene>> ResourceManager::Scenes;
  std::map<std::string, Sound> ResourceManager::Sounds;
  std::map<std::string, Music> ResourceManager::Musics;

  Texture2D ResourceManager::LoadTexture(const char *file, std::string name){
    if(Textures[name].id <= 0){
      Textures[name] = ::LoadTexture(file);
    }
    return Textures[name];
  }


  Texture2D ResourceManager::GetTexture(std::string name){
    return Textures[name];
  }

  Font ResourceManager::LoadFont(const char *file, std::string name){
    if(Fonts[name].texture.id <= 0){
      Fonts[name] = ::LoadFontEx(file, 64, 0, 0);
    }

    return Fonts[name];
  }

  Font ResourceManager::GetFont(std::string name){
    return Fonts[name];
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

  Music ResourceManager::LoadMusic(const char *file, std::string name){
    Musics[name] = LoadMusicStream(file);
    return Musics[name];
  }

  Music ResourceManager::GetMusic(std::string name){
    return Musics[name];
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

    for(auto& font: Fonts){
      UnloadFont(font.second);
    }

    for(auto& sound : Sounds){
      UnloadSound(sound.second);
    }

    for(auto& music: Musics){
      UnloadMusicStream(music.second);
    }
  }
  
  
}
