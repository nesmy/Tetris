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
      if(currentBlock->IsBlockOutside() || currentBlock->BlockFits() == false){
	currentBlock->Move(-1, 0);
	currentBlock->LockBlock();
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

  virtual std::shared_ptr<BB::Scene> update() override {
    BB::Scene::update();
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
    currentBlock->Draw();
  }

  std::shared_ptr<Grid> grid;
private:
  std::vector<std::shared_ptr<Block>> blocks;
  std::shared_ptr<Block> currentBlock;
  std::shared_ptr<Block> nextBlock;
  double lastUpdateTime = 0;
  bool gameOver = false;
  
  
};
