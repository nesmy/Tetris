#pragma once

#include "Object.h"

class Grid : public BB::Object{
 public:
  Grid();
  ~Grid();

  void Init();
  void Print();
  bool IsCellOutside(int row, int column);
  bool IsCellEmpty(int row, int column);
  int ClearFullRows();

  virtual void Draw() override;
private:
  bool IsRowFull(int row);
  void ClearRow(int row);
  void MoveRowDown(int row, int numRows);
 public:
  int grid[20][10];
 private:
  int numRows;
  int numCols;
  int cellSize;
  std::vector<Color> colors;
};
