#include "Application.h"
#include "Menu.h"
#include "Over.h"
#include "ResourceManager.h"
#include "Start.h"
#include "Tetris.h"

using namespace BB;

int main(void){
  int retVal = EXIT_SUCCESS;
  Application<StartScene> App(500, 620, "Tetris");
  
  ResourceManager::LoadScene<Tetris>("Game");
  ResourceManager::GetScene("Game")->loadResources();
  ResourceManager::GetScene("Game")->start();
  ResourceManager::LoadScene<OverMenuScene>("Over");
  ResourceManager::LoadScene<MenuScene>("Menu");
  try{
    App.RunLoop();
  }
  catch(std::runtime_error &e){
    showErrorAndExit(e.what());
    retVal = EXIT_FAILURE;
  }

  ResourceManager::Clear();
  
  return retVal;
}
