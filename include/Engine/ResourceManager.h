#pragma once
#include "Config.h"

namespace BB {
  class Object;
  class Scene;
  class ResourceManager {
  public:
    //resouce storage
    static std::map<std::string, Texture2D> Textures;
    static std::map<std::string, Font> Fonts;
    static std::vector<Object*> Objects;
    static std::map<std::string, std::shared_ptr<Scene>> Scenes;
    static std::map<std::string, Sound> Sounds;
    static std::map<std::string, Music> Musics;
    // loads texture from file
    static Texture2D LoadTexture(const char* file, std::string name);
    // retrieves a stored texture
    static Texture2D GetTexture(std::string name);

    static Font LoadFont(const char* file, std::string name);
    static Font GetFont(std::string name);

    static Sound LoadSound(const char* file, std::string name);
    static Sound GetSound(std::string nanme);

    static Music LoadMusic(const char* file, std::string name);
    static Music GetMusic(std::string name);

    static void AddObject(Object* object);
    static std::vector<Object*> GetObjects();

    //Load Scene
    template<class T>
    static std::shared_ptr<Scene> LoadScene(std::string name){
      Scenes[name] = std::make_unique<T>();
      return Scenes[name];
    }
    // Retrieves a stored scene
    static std::shared_ptr<Scene> GetScene(std::string name){
      return Scenes[name];
    }
    
    // properly de-allocates all loaded resources
    static void Clear();
  private:
    ResourceManager() {}
  };
  
    }
