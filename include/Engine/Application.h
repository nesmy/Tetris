#pragma once
#include "InputHandler.h"
#include "Renderer.h"
#include "Scene.h"
#include "Window.h"
#include <memory>

namespace BB {
  template <class scene>
  class Application{
  public:
    Application(int width, int height, const char* title){
      window = std::make_unique<Window>(width, height, title);
      renderer = std::make_unique<Renderer>();
      inputHandler = std::make_unique<InputHandler>();
      currScene = std::make_shared<scene>();
      currScene->loadResources();
      currScene->start();
      
    }

    ~Application(){
    }

    void RunLoop(){
      // SetUp();

      bool quit = false;
      while (!quit) {
        
	//update
	inputHandler->handleInput(*currScene);

	renderer->Render(currScene);

	quit = WindowShouldClose() || currScene->shouldQuit();
      }
    }
  private:
    std::unique_ptr<Window> window;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<InputHandler> inputHandler;
  public:
    std::shared_ptr<Scene> currScene;
  };
  
    }
