#pragma once
#include "InputHandler.h"
#include "Renderer.h"
#include "Scene.h"
#include "Window.h"

namespace BB {
  template <class scene>
  class Application{
  public:
    Application(){
      window = new Window(WIDTH, HEIGHT, "Pong");
      renderer = new Renderer();
      inputHandler = new InputHandler();
      currScene = std::make_shared<scene>();
      currScene->loadResources();
      currScene->start();
      
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
    Window *window;
    Renderer* renderer;
    InputHandler* inputHandler;
  public:
    std::shared_ptr<Scene> currScene;
  };
  
    }
