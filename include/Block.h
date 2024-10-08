#pragma once

#include "Grid.h"
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
  void Draw(int offsetX, int offsetY);
  void Rotate();
  void UndoRotation();
  std::vector<PositionCell> GetCellPositions();
 public:
  int id;
  std::shared_ptr<Grid> grid;
  bool gameOver;
  std::map<int, std::vector<PositionCell>> cells;
  std::shared_ptr<Block> nextBlock;
 private:
  int cellSize;
  int rotationState;
  std::vector<Color> colors;
  int rowoffset;
  int columnOffset;
};


