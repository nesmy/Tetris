#pragma once
#include "Config.h"
#include "Scene.h"

namespace BB {
  class Renderer {
  public:
    Renderer(){
    }
    ~Renderer(){
      std::cout << "outRender" << std::endl;
    }

    void Render(std::shared_ptr<Scene> &currScene){
      auto nextScene = currScene->update();
      if(nextScene){
	// nextScene->loadResources();
	nextScene->start();
	currScene = nextScene;
	
      }

      // draw
      BeginDrawing();
      //ClearBackground(BLACK);
      //Update();
      currScene->Draw();
      EndDrawing();
    }
  private:
  };
    }
