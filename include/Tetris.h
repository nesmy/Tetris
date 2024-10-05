#pragma once
#include "Scene.h"


class Tetris : public BB::Scene{
 public:
  Tetris(){
  }

  virtual ~Tetris(){
  }

  virtual void Draw() override{
    DrawText("Tetris", GetScreenWidth() / 2, GetScreenHeight() / 2, 40, RED);
  }
};
