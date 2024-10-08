#pragma once
#include "Block.h"
#include "Blocks.h"
#include "Scene.h"
#include "Grid.h"


class Tetris : public BB::Scene{
 public:
  Tetris(){
  }

  virtual ~Tetris(){
  }

  virtual void loadResources() override{
    grid = std::make_unique<Grid>();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    currentBlock->gameOver = gameOver;
    currentBlock->grid = grid;
    nextBlock = GetRandomBlock();
    // Objects.emplace_back(grid);

    // for(auto& block : blocks){
    //   Objects.emplace_back(block);
    // }
    playerAvatar = currentBlock; 
  }

  bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

  void MoveBlockDown(){
    if(!gameOver){
      currentBlock->Move(1, 0);
      if(IsBlockOutside() || BlockFits() == false){
	currentBlock->Move(-1, 0);
        LockBlock();
      }
    }
  }

  std::shared_ptr<Block> GetRandomBlock(){
    if(blocks.empty()){
      blocks = GetAllBlocks();
    }
    int randimIndex = rand() % blocks.size();
    std::shared_ptr<Block> block = blocks[randimIndex];
    blocks.erase(blocks.begin() + randimIndex);
    return block;
  }

  std::vector<std::shared_ptr<Block>> GetAllBlocks(){

    return {std::make_unique<IBlock>(),std::make_unique<JBlock>(),std::make_unique<LBlock>(),
	    std::make_unique<OBlock>(),std::make_unique<SBlock>(),std::make_unique<TBlock>(),
	    std::make_unique<ZBlock>()};
  }

  void handleInput(){
    int keyPressed = GetKeyPressed();
    if (gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        // UpdateScore(0, 1);
        break;
    case KEY_UP:
        RotateBlock();
        break;
    }
  }

  virtual std::shared_ptr<BB::Scene> update() override {
    BB::Scene::update();
    handleInput();
    if(EventTriggered(0.2)){
      MoveBlockDown();
    }
    return nullptr;
  }

  virtual void Draw() override{
    BB::Scene::Draw();
    Color darkBlue = {44, 44, 127, 255};
    ClearBackground(darkBlue);
    grid->Draw();
    currentBlock->Draw(11, 11);
    switch (nextBlock->id)
    {
    case 3:
        nextBlock->Draw(255, 290);
        break;
    case 4:
        nextBlock->Draw(255, 280);
        break;
    default:
        nextBlock->Draw(270, 270);
        break;
    }
  }

  std::shared_ptr<Grid> grid;
private:
  void MoveBlockLeft(){
    if (!gameOver)
      {
        currentBlock->Move(0, -1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock->Move(0, 1);
        }
    }
  }
  void MoveBlockRight(){
    if (!gameOver)
    {
        currentBlock->Move(0, 1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock->Move(0, -1);
        }
    }
  }

  bool IsBlockOutside(){
    std::vector<PositionCell> tiles = currentBlock->GetCellPositions();
    for (PositionCell item : tiles)
    {
        if (grid->IsCellOutside(item.row, item.column))
        {
            return true;
        }
    }
    return false;
  }
  void RotateBlock(){
    if (!gameOver)
    {
        currentBlock->Rotate();
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock->UndoRotation();
        }
        else
        {
            // PlaySound(rotateSound);
        }
    }
  }
  void LockBlock(){
    std::vector<PositionCell> tiles = currentBlock->GetCellPositions();
    for (PositionCell item : tiles)
    {
        grid->grid[item.row][item.column] = currentBlock->id;
    }
    currentBlock = nextBlock;
    if (BlockFits() == false)
    {
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    int rowsCleared = grid->ClearFullRows();
    if (rowsCleared > 0)
    {
        // PlaySound(clearSound);
        // UpdateScore(rowsCleared, 0);
    }
  }
  bool BlockFits(){
    std::vector<PositionCell> tiles = currentBlock->GetCellPositions();
    for (PositionCell item : tiles)
    {
        if (grid->IsCellEmpty(item.row, item.column) == false)
        {
            return false;
        }
    }
    return true;
  }
  void Reset(){
    grid->Init();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    // score = 0;
  }
private:
  std::vector<std::shared_ptr<Block>> blocks;
  std::shared_ptr<Block> currentBlock;
  std::shared_ptr<Block> nextBlock;
  double lastUpdateTime = 0;
  bool gameOver = false;
  
  
};
