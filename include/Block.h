#pragma once

#include "Object.h"
#include "Colors.h"

class PositionCell{
 public:
  PositionCell(int row, int column){
    this->row = row;
    this->column = column;
  }

  int row;
  int column;
};

class Block : public BB::Object{
 public:
  Block();
  ~Block();

  virtual void Draw() override;
  void Move(int rows, int column);
 private:
  std::vector<PositionCell> GetCellPositions();
 public:
  int id;
  std::map<int, std::vector<PositionCell>> cells;
 private:
  int cellSize;
  int rotationState;
  std::vector<Color> colors;
  int rowoffset;
  int columnOffset;
};


