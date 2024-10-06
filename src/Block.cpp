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
    DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize -1, cellSize -1, colors[id]);
  }
}

void Block::Move(int rows, int column){
  rowoffset += rows;
  columnOffset += column;
}

bool Block::IsBlockOutside(){
  std::vector<PositionCell> tiles = GetCellPositions();
  for(PositionCell item : tiles){
    if(grid->IsCellEmpty(item.row, item.column)){
      return true;
    }
  }
  return false;
}

bool Block::BlockFits(){
  std::vector<PositionCell> tiles = GetCellPositions();
  for(PositionCell item : tiles){
    if(grid->IsCellEmpty(item.row, item.column) == false){
      return false;
    }
  }

  return true;
}

void Block::LockBlock(){
  std::vector<PositionCell> tiles = GetCellPositions();
  for(PositionCell item : tiles){
    grid->grid[item.row][item.column] = id;
  }
  
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

void Block::goUp() {
  if(!gameOver){
    Rotate();
    if(IsBlockOutside() || BlockFits() == false){
      UndoRotation();
    }
    else{
    }
  }
}

void Block::goDown() {
  if(!gameOver){
    Move(1, 0);
    if(IsBlockOutside() || BlockFits() == false){
      Move(-1, 0);
      LockBlock();
    }
  }
}

void Block::goLeft() {
  if(!gameOver){
    Move(0, -1);
    if(IsBlockOutside() || BlockFits() == false){
      Move(0, 1);
    }
  }
}

void Block::goRight() {
  if(!gameOver){
    Move(0, 1);
    if(IsBlockOutside() || BlockFits() == false){
      Move(0, -1);
    }
  }
}
