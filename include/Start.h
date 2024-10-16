#pragma once

#include "ResourceManager.h"
#include "Scene.h"
#include "Colors.h"

class StartScene : public BB::Scene{
 public:
  StartScene(){
    start = false;
    PlayMusicStream(BB::ResourceManager::LoadMusic("Resources/Sounds/music2.mp3", "Music2"));
  }

  virtual ~StartScene() override{
  }

  virtual std::shared_ptr<BB::Scene> update() override{
    UpdateMusicStream(BB::ResourceManager::GetMusic("Music2"));
    if(start){
      start = false;
      BB::ResourceManager::GetScene("Game")->loadResources();
      BB::ResourceManager::GetScene("Game")->start();
      return BB::ResourceManager::GetScene("Game");
    }
    else {
      return nullptr;
	}
  }

  virtual void Draw() override{
    BB::Scene::Draw();
    ClearBackground(lightBlue);

    int sceneWidth = GetScreenWidth();
    int sceneHeight = GetScreenHeight();

    const char *title = "Tetris";
    Font titleFont = BB::ResourceManager::GetFont("monogram");
    Vector2 titleDim = MeasureTextEx(titleFont, title, TITLE_FONT_SIZE, TITLE_FONT_SPACING);

    int titleLeft = (sceneWidth - titleDim.x) / 2;
    int titleTop = sceneHeight / 4 - titleDim.y / 2;
    Vector2 titlePos = Vector2{(float)titleLeft, (float)titleTop};
    ::DrawTextEx(titleFont, title, titlePos, TITLE_FONT_SIZE, TITLE_FONT_SPACING, RED);

    int menuLeft = (sceneWidth - BUTTON_WIDTH) / 2;
    int menuTop = sceneHeight / 2;
    float currX = (float)menuLeft;
    float currY = (float)menuTop;

    GuiSetStyle(BUTTON, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
    GuiSetStyle(DEFAULT, TEXT_SIZE, MENU_FONT_SIZE);
    if(GuiButton((Rectangle){currX, currY, BUTTON_WIDTH, BUTTON_HEIGHT}, "Start Game")){
      start = true;
    }
   
  }

 private:
  bool start;
};
