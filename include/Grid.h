#pragma once

#include "Object.h"

class Grid : public BB::Object{
 public:
  Grid();
  ~Grid();

  void Init();
  void Print();

  virtual void Draw() override;
 public:
  int grid[20][10];
 private:
  int numRows;
  int numCols;
  int cellSize;
  std::vector<Color> colors;
};
