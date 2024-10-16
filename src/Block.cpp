#include "Block.h"
#include "Colors.h"

Block::Block() {
  cellSize = 30;
  rotationState = 0;
  colors = GetCellColors();
  rowoffset = 0;
  columnOffset = 0;
}

Block::~Block() {}

void Block::Draw() {
  std::vector<PositionCell> tiles = GetCellPositions();
  for(PositionCell item : tiles){
    DrawRectangle(item.column * cellSize + 11, item.row * cellSize + 11, cellSize -1, cellSize -1, colors[id]);
  }
}

void Block::Draw(int offsetX, int offsetY){
  std::vector<PositionCell> tiles = GetCellPositions();
  for(PositionCell item : tiles){
    DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize -1, cellSize -1, colors[id]);
  }
}

void Block::Move(int rows, int column){
  rowoffset += rows;
  columnOffset += column;
}

std::vector<PositionCell> Block::GetCellPositions(){

  std::vector<PositionCell> tiles = cells[rotationState];
  std::vector<PositionCell> movedTiles;
  for(PositionCell item : tiles){
    PositionCell newPos = PositionCell(item.row + rowoffset, item.column + columnOffset);
    movedTiles.emplace_back(newPos);
  }

  return movedTiles;
}

void Block::Rotate() {
  rotationState++;
  if(rotationState == (int)cells.size()){
    rotationState = 0;
  }
}

void Block::UndoRotation(){
  rotationState--;
  if(rotationState == -1){
    rotationState = cells.size() - 1;
  }
}
