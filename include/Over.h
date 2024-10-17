#pragma once

#include "ResourceManager.h"
#include "Scene.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

class OverMenuScene : public BB::Scene{
 public:
  OverMenuScene(){
    restartClicked = false;
    quit = false;
  }

  virtual ~OverMenuScene(){
  }

  virtual std::shared_ptr<BB::Scene> update() override{
    if(restartClicked){
      restartClicked = false;
      return BB::ResourceManager::GetScene("Game");
    }
    else {
      return nullptr;
    }
  }

  virtual bool shouldQuit() override{
    return quit;
  }

  virtual void Draw() override{
    BB::Scene::Draw();
    // PlaySound(Over);
    int sceneWidth = GetScreenWidth();
    int sceneHeight = GetScreenHeight();

    const char *title = "Game Over";
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
    if(GuiButton((Rectangle){currX, currY, BUTTON_WIDTH, BUTTON_HEIGHT}, "Restart")){
      restartClicked = true;
    }
    currY += BUTTON_SPACING;
    if(GuiButton((Rectangle){currX, currY, BUTTON_WIDTH, BUTTON_HEIGHT}, "Quit")){
      quit = true;
    }
  }

  virtual void doExit() override{
    quit = true;
  }

 private:
  bool restartClicked;
  bool quit;
  
};
